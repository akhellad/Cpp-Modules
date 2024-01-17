/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:59:42 by akhellad          #+#    #+#             */
/*   Updated: 2024/01/17 17:32:25 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include <cctype>
#include <stdexcept>

BitcoinExchange::BitcoinExchange()
{
    try
    {
        _fillExchangeMap();
    }
    catch(const std::exception& e)
    {
        std::string error = e.what();
        throw(std::runtime_error("Invalid exchange rate : " + error));
    } 
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &src)
{
    this->_exchangeRate = src._exchangeRate;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange &src)
{
    this->_exchangeRate = src._exchangeRate;
    return (*this);
}

void BitcoinExchange::_fillExchangeMap()
{
    std::string path = "./data.csv";
    struct stat filechecker;
    if(stat(path.c_str(), &filechecker) != 0)
        throw(std::runtime_error(path + ": invalid file."));
    if((filechecker.st_mode & S_IFREG) == 0)
        throw(std::runtime_error(path + ": is a directory."));
    if ((filechecker.st_mode & S_IXUSR) != 0)
        throw(std::runtime_error(path + ": is an executable."));
    std::fstream fstream;
    fstream.open(path.c_str(), std::fstream::in);
    if(fstream.fail())
        throw(std::runtime_error("Could not open data file"));
    char    line[100];
    fstream.getline(line, 100);
    while (!fstream.eof())
    {
        char line[100];
        fstream.getline(line, 100);
        if (!fstream.eof() && line[0] != '\0')
            _fillExchangeEntry(std::string(line));
    }
}

void BitcoinExchange::_fillExchangeEntry(std::string line)
{
    std::string *split = splitString(line, ",");
    _checkDate(split[DATE]);
    _checkValue(split[VALUE]);

    time_t date = _getDateFromString(split[DATE]);
    double  value = _getValue(split[VALUE]);

    _addExchangeEntry(date, value);
    delete[] split;
}

void BitcoinExchange::_addExchangeEntry(time_t date, double value)
{
    std::map<time_t, double>::iterator it = _exchangeRate.find(date);
    if(it != _exchangeRate.end())
        it->second = value;
    else
        _exchangeRate.insert(std::pair<time_t, double>(date, value));
}

void BitcoinExchange::displayExchangeValue(std::string &dateStr, std::string &valueStr)
{
    _checkInput(dateStr, valueStr);
    time_t date = _getDateFromString(dateStr);
    double value = _getValue(valueStr);
    if (value < 0 || value > 1000)
        throw std::out_of_range("Invalid value : must be between 0 and 1000");
    double exchangeRate = _getExchangeRateOnDate(date);
    double exchangeValue = getExchangeValue(dateStr, valueStr);
    if (VERBOSE)
        _printExchangeRate(date);
    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout << "[" << _getDate(date) << "]" << value << " * ";
    std::cout << exchangeRate << " = " << exchangeValue << std::endl;
}

void    BitcoinExchange::_printExchangeRate(time_t date)
{
    time_t closestEpoch = _getClosestDate(date);
    std::string closestDate = _getDate(closestEpoch);

    std::cout << "Closest exchange data : " << closestDate << " -> ";
    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout << _exchangeRate[closestEpoch] << std::endl;
}

double BitcoinExchange::getExchangeValue(std::string &dateStr, std::string &valueStr)
{
    _checkInput(dateStr, valueStr);
    double rate = _getExchangeRateOnDate(_getDateFromString(dateStr));
    double value = _getValue(valueStr);
    return (value * rate);
}

double BitcoinExchange::_getExchangeRateOnDate(time_t date)
{
    time_t closestDate = _getClosestDate(date);
    return (_exchangeRate[closestDate]);
}

time_t BitcoinExchange::_getClosestDate(time_t date)
{
    std::map<time_t, double>::iterator it = _exchangeRate.find(date);
    if (date < _exchangeRate.begin()->first)
        return (_exchangeRate.begin()->first);
    for (int i = 0; it == _exchangeRate.end(); i++)
    {
        time_t newDate = date - i * 24 * 60 * 60;
        it = _exchangeRate.find(newDate);
    }
    return (it->first);
}

time_t BitcoinExchange::_getDateFromString(std::string &dateStr) const{
    struct tm tm;
    bzero(&tm, sizeof(tm));
    tm.tm_year = _getYear(dateStr) - 1900;
    tm.tm_mon = _getMonth(dateStr) - 1;
    tm.tm_mday = _getDay(dateStr);

    struct tm cpy;
    bzero(&cpy, sizeof(cpy));
    cpy.tm_year = tm.tm_year;
    cpy.tm_mon = tm.tm_mon;
    cpy.tm_mday = tm.tm_mday;

    time_t date = mktime(&tm);
    if(date == -1 || cpy.tm_year != tm.tm_year || cpy.tm_mon != tm.tm_mon || cpy.tm_mday != tm.tm_mday)
        throw(std::out_of_range(dateStr + " : invalid date"));
    return (date);
}

int BitcoinExchange::_getYear(std::string &dateStr) const
{
    size_t yearLen = dateStr.find("-", 0);
    std::string yearStr = dateStr.substr(0, yearLen);
    int year = std::atoi(yearStr.c_str());
    if (yearStr.empty() || year < 2008 || year > 2050)
        throw std::out_of_range(dateStr + " : invalid date");
    return (year);
}

int BitcoinExchange::_getMonth(std::string &dateStr) const
{
    size_t yearLen = dateStr.find("-", 0) + 1;
    size_t monthLen = dateStr.find("-", yearLen) - yearLen;
    std::string monthStr = dateStr.substr(yearLen, monthLen);
    int month = std::atoi(monthStr.c_str());
    if (monthStr.empty() || month < 0 || month > 12)
        throw(std::out_of_range(dateStr + " : invalid date"));
    return (month);
}

int BitcoinExchange::_getDay(std::string &dateStr) const
{
    size_t yearLen = dateStr.find("-", 0) + 1;
    size_t monthLen = dateStr.find("-", yearLen) + 1;
    size_t dayLen = dateStr.length() - monthLen;
    std::string dayStr = dateStr.substr(monthLen, dayLen);
    try
    {
        _checkDay(dayStr);
    }
    catch(const std::exception& e)
    {
        throw std::out_of_range(dateStr + " : invalid date");
    }
     int day = std::atoi(dayStr.c_str());
     if (dayStr.empty() || day < 1 || day > 31)
        throw std::out_of_range(dateStr + " : invalid date");
    return (day);
}

std::string const BitcoinExchange::_getDate(time_t epochDate) const
{
    struct tm *date = localtime(&epochDate);
    std::stringstream ss;

    ss << std::setfill('0') << std::setw(4) << date->tm_year + 1900;
    ss << "-" << std::setfill( '0' ) << std::setw( 2 ) << date->tm_mon + 1;
	ss << "-" << std::setfill( '0' ) << std::setw( 2 ) << date->tm_mday;
	return ( ss.str() );
}

double  BitcoinExchange::_getValue(std::string &valueStr) const
{
    double value = std::strtod(valueStr.c_str(), NULL);
    if (value < 0)
        throw (std::out_of_range(valueStr + " :  not a positive value"));
    else if (value > std::numeric_limits<int>::max())
        throw (std::out_of_range(valueStr + " : too high value"));
    return (value);
}

void  BitcoinExchange::_checkInput(std::string &dateStr, std::string &valueStr) const
{
    _checkDate(dateStr);
    _checkValue(valueStr);
}

void    BitcoinExchange::_checkValue(std::string &valueStr) const
{
    if (isStringEmpty(valueStr) == true)
        throw(std::runtime_error("no value"));
    std::string accepted = "0123456789";
    size_t pos = valueStr.find_first_of(accepted, 0);
    if (pos == std::string::npos)
        throw(std::runtime_error(valueStr + " : invalid value"));
    std::string::iterator it = valueStr.begin();
    for ( ; it != valueStr.end(); it++)
    {
        if (std::isalpha(*it) || !std::isprint(*it))
            throw(std::runtime_error(valueStr + " : invalid value"));
    }
    size_t decimalCount = std::count(valueStr.begin(), valueStr.end(), '.');
    if (decimalCount > 1) {
        throw std::runtime_error(valueStr + " : invalid value (multiple decimal points)");
    }
    if (valueStr.size() > 1 && valueStr[0] == '0' && valueStr[1] != '.') {
        throw std::runtime_error(valueStr + " : invalid value (leading zeros)");
    }
}

void    BitcoinExchange::_checkDate(std::string &dateStr) const
{
    if (isStringEmpty(dateStr))
        throw(std::runtime_error("no date"));
    std::string accepted = "0123456789-";
    size_t pos = dateStr.find_first_of(accepted, 0);
    if (pos == std::string::npos)
        throw(std::runtime_error(dateStr + " : invalid date"));
    std::string::iterator it = dateStr.begin();
    for ( ; it != dateStr.end(); it++)
    {
        if (std::isalpha(*it) || !std::isprint(*it))
            throw(std::runtime_error(dateStr + " : invalid date"));
    }
}

void    BitcoinExchange::_checkDay(std::string &dayStr) const
{
    std::string::iterator it = dayStr.begin();
    for ( ; it != dayStr.end(); it++)
    {
        if (std::isdigit(*it) == false && isblank(*it) == false)
        	throw std::out_of_range( "invalid date" );
    }
}