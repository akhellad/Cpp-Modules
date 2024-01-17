/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:17:17 by akhellad          #+#    #+#             */
/*   Updated: 2024/01/04 14:27:56 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::argType ScalarConverter::_argType = UNKNOWN;

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	this->_argType = other._argType;
}

ScalarConverter::~ScalarConverter(){}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
		this->_argType = other.getArgType();
	return (*this);
}

void	ScalarConverter::setArgType(argType type)
{
	_argType = type;
}

ScalarConverter::argType	ScalarConverter::getArgType()
{
	return (_argType);
}

bool	check_input(std::string &input)
{
	bool hasF = false;
	bool hasDot = false;
	bool hasSign = false;
	if(input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff")
		return (true);
	for(size_t i = 0; i < input.size(); i++)
	{
		if(i != 0 && (input[i] != 'f' && input[i] != '.' && input[i] != '+' && input[i] != '-' && !isdigit(input[i])))
			return (false);
		if(input[i] == '.')
		{
			if(hasDot)
				return (false);
			else
				hasDot = true;
		}
		if(input[i] == 'f')
		{
			if(hasF)
				return (false);
			else
				hasF = true;
		}
		if(input[i] == '+' || input[i] == '-')
		{
			if(hasSign)
				return (false);
			else
				hasSign = true;
		}
	}
	if(hasF && !hasDot)
		return (false);
	return (true);
}

void parsing(std::string const &input)
{
    if(input.size() == 1)
    {
        if(std::isdigit(input[0]))
            ScalarConverter::setArgType(ScalarConverter::INT);
        else
            ScalarConverter::setArgType(ScalarConverter::CHAR);
    }
    else if(input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff" || input == "nan" || input == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input << std::endl;
        std::cout << "double: " << input << std::endl;
        return ;
    }
    else if(input.find(".") != std::string::npos)
    {
        if(input.find("f") != std::string::npos)
            ScalarConverter::setArgType(ScalarConverter::FLOAT);
        else
            ScalarConverter::setArgType(ScalarConverter::DOUBLE);
    }
    else
        ScalarConverter::setArgType(ScalarConverter::INT);
}

void	ScalarConverter::convert(std::string &input)
{
	switch(ScalarConverter::getArgType())
	{
		case(ScalarConverter::CHAR):
			ScalarConverter::CharConverter(input);
			break;
		case(ScalarConverter::INT):
			ScalarConverter::IntConverter(input);
			break;
		case(ScalarConverter::FLOAT):
			ScalarConverter::FloatConverter(input);
			break;
		case(ScalarConverter::DOUBLE):
			ScalarConverter::DoubleConverter(input);
			break;
		default:
			std::cout << "Error: Unknown type" << std::endl;
			break;
	}
}