/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatConverter.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:55:00 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/02 12:01:22 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

void	ScalarConverter::FloatConverter(std::string &input)
{
	input.erase(input.size() - 1);
	std::stringstream ss(input);
	float f;
	ss >> f;

	if(ss.fail())
	{
		std::cerr << "Invalid input" << std::endl;
		return ;
	}
	int checkInput = static_cast<int>(f);
	if (checkInput < 0 || checkInput > 127)
		std::cout << "char: Non ASCII" << std::endl;
	else if (checkInput < 32 || checkInput > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(checkInput) << "'" << std::endl;
	std::cout << "int: " << checkInput << std::endl;
	if((checkInput - f) == 0)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	if((checkInput - f) == 0)
		std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(f) << std::endl;
}