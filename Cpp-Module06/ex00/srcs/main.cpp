/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:13:36 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/02 11:28:35 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./convert [literal]" << std::endl;
		return (1);
	}
	std::string arg = av[1];
	if (arg.length() == 0)
	{
		std::cerr << "Empty literal" << std::endl;
		return (1);
	}
	std::string tmp(av[1]);
	if (!check_input(tmp))
		std::cerr << "Invalid input" << std::endl;
	else
	{
		parsing(arg);
		ScalarConverter::convert(arg);
	}
	return (0);
}