/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:42:58 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/08 14:40:58 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
# define BITCOINEXCHANGE_H

# define DATE 0
# define VALUE 1
# define VERBOSE 1

# include <cstdlib>
# include <ctime>
# include <exception>
# include <fstream>
# include <iomanip>
# include <iostream>
# include <limits>
# include <map>
# include <sstream>
# include <stdexcept>
# include <string>
# include <strings.h>
# include <sys/stat.h>

class BitcoinExchange
{
private:
    std::map<time_t, double>_exchangeRate;

    void    _fillExchangeMap();
    void    _fillExchangeEntry(std::string fill);
    void    _addExchangeEntry(time_t date, double value);
    time_t  _getClosestDate(time_t date);
    double  _getExchangeRateOnDate( time_t date );
    time_t  _getDateFromString(std::string &date) const;
    int     _getYear(std::string &litteralDate) const;
    int     _getMonth(std::string &litteralDate) const;
    int     _getDay(std::string &litteralDate) const;
    std::string const   _getDate(time_t litteralDate) const;
    double  _getValue(std::string &litteralValue) const;
    void    _checkInput(std::string &date, std::string &value) const;
    void    _checkValue(std::string &input) const;
    void    _checkDate(std::string &input) const;
    void    _checkDay(std::string &input) const;
    void    _printExchangeRate(time_t date);
public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange &src);
    ~BitcoinExchange();

    BitcoinExchange &operator=(BitcoinExchange &src);

    void    displayExchangeValue(std::string &date, std::string &value);
    double  getExchangeValue(std::string &date, std::string &value);
};

std::string    *splitString(std::string string, std::string sep);
bool           isStringEmpty(std::string string);

#endif 