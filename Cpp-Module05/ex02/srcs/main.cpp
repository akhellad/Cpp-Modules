/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:34:08 by akhellad          #+#    #+#             */
/*   Updated: 2024/01/04 14:02:27 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat	lowlyBureaucrat("Lowly Larry", 142);
	Bureaucrat	averageBureaucrat("Average Andy", 65);
	Bureaucrat	highBureaucrat("High Harry", 6);

	std::cout << "Bureaucrats\n"
			<< lowlyBureaucrat << "\n"
			<< averageBureaucrat << "\n"
			<< highBureaucrat << std::endl;
	
	ShrubberyCreationForm	shrubForm("Forest");
	RobotomyRequestForm		robotomyForm("CEO");
	PresidentialPardonForm	pardonForm(highBureaucrat.getName());

	std::cout << std::endl << "Forms:\n"
			<< shrubForm << "\n"
			<< robotomyForm << "\n"
			<< pardonForm << std::endl;

	std::cout << std::endl << "-- Signing and executing Shrubbery form:" << std::endl;
	lowlyBureaucrat.signForm(shrubForm);
	lowlyBureaucrat.executeForm(shrubForm);
	averageBureaucrat.executeForm(shrubForm);

	std::cout << std::endl << "-- Signing and executing Presidential Pardon form:" << std::endl;
	highBureaucrat.executeForm(pardonForm);
	highBureaucrat.signForm(pardonForm);
	highBureaucrat.executeForm(pardonForm);
	highBureaucrat.incrementGrade();
	highBureaucrat.executeForm(pardonForm);

	std::cout << std::endl << "-- Signing and executing Robotomy form:" << std::endl;
	averageBureaucrat.executeForm(robotomyForm);
	averageBureaucrat.signForm(robotomyForm);
	averageBureaucrat.executeForm(robotomyForm);
	highBureaucrat.executeForm(robotomyForm);

	std::cout << std::endl;
	return (0);
}

