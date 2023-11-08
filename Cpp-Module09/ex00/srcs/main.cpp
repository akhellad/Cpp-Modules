/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:11:39 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/08 14:44:53 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

void    checkArgs(int ac, char **av);
std::fstream *openFile(char *file);
void evaluateInput(BitcoinExchange &btc, std::fstream &fs);
bool checkLineEvaluation(char *line);
bool isStringEmpty(std::string string);

int main(int ac, char **av)
{
    BitcoinExchange *btc = NULL;
    std::fstream *fs = NULL;
    try
    {
        checkArgs(ac, av);
        fs = openFile(av[1]);
        btc = new BitcoinExchange();
        evaluateInput(*btc, *fs);
    }
    catch(std::exception &e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
        delete btc;
        delete fs;
        return (1);
    }
    delete btc;
    delete fs;
    return (0);
}

void checkArgs(int ac, char **av)
{
    (void)av;
    if (ac != 2)
        throw(std::runtime_error("Usage : ./btc <file>"));
}

std::fstream *openFile(char *file)
{
    std::string path = file;
    struct stat filechecker;
    if (stat(file, &filechecker) != 0)
        throw(std::runtime_error(path + " : invalid file"));
	else if ((filechecker.st_mode & S_IFREG) == 0 )
		throw (std::runtime_error( path + ": is a directory" ) );
	else if ((filechecker.st_mode & S_IXUSR) != 0 )
		throw( std::runtime_error( path + ": is an executable"));
    std::fstream *fs = new std::fstream();
    fs->open(file, std::fstream::in);
    if (fs->fail())
    {
        delete fs;
        throw(std::runtime_error(path + " : could not open file"));
    }
    return (fs);
}

void    evaluateInput(BitcoinExchange &btc, std::fstream &fs)
{
    int i = 0;
    while(!fs.eof())
    {
        char line[100];
        fs.getline(line, 100);
        if (fs.eof() || checkLineEvaluation(line) == false)
        {
            i++;
            continue;
        }
        if (VERBOSE)
            std::cout << std::endl << line << std::endl;
        std::string *split = NULL;
        try
        {
            split = splitString(line, "|");
            btc.displayExchangeValue(split[DATE], split[VALUE]);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error : " << e.what() << " (line " << i << ": " << line << ")" << 
            std::endl;
        }
        delete[] split;
        i++;
    }
}

bool checkLineEvaluation(char *line)
{
    std::string lineStr(line);
    if (isStringEmpty(line) == true || lineStr == "date | value")
        return false;
    return true;
}

bool isStringEmpty(std::string string)
{
    if(string.empty())
        return true;
    std::string::iterator it = string.begin();
    for( ; it != string.end(); it++)
    {
        if (!isblank(*it))
            return false;
    }
    return true;
}

std::string *splitString(std::string string, std::string set)
{
    std::string *split = new std::string[2];
    size_t delim = string.find(set, 0);
    if (delim == std::string::npos)
    {
        delete[] (split);
        throw(std::out_of_range(string + " : invalid input"));
    }
    split[DATE] = string.substr(0, delim);
    split[VALUE] = string.substr(delim + set.length(), std::string::npos);
    return (split);
}