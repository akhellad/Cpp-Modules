/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:45:25 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/02 11:54:13 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

void	ScalarConverter::DoubleConverter(std::string const &input)
{
	std::stringstream ss(input);
	double d;
	ss >> d;

	if(ss.fail())
	{
		std::cerr << "Invalid input" << std::endl;
		return ;
	}
	int checkInput = static_cast<int>(d);
	if (checkInput < 0 || checkInput > 127)
		std::cout << "char: Non ASCII" << std::endl;
	else if (checkInput < 32 || checkInput > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(checkInput) << "'" << std::endl;
	std::cout << "int: " << checkInput << std::endl;
	if((checkInput - d) == 0)
		std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	if((checkInput - d) == 0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}