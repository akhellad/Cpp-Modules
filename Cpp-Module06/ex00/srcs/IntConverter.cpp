/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntConverter.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:01:27 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/02 12:04:42 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

void	ScalarConverter::IntConverter(std::string const &input)
{
	std::stringstream ss(input);
	int i;
	ss >> i;
	ss.str();

	if(ss.fail())
	{
		std::cerr << "Invalid input" << std::endl;
		return ;
	}
	if (i < 0 || i > 127)
		std::cout << "char: Non ASCII" << std::endl;
	else if (i < 32 || i > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}