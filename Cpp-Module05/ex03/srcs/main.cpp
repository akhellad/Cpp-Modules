/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:34:08 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/01 14:36:19 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"
#include <iostream>

#define RESET	"\e[0m"
#define RED		"\e[31m"

void	testInternFormCreation(std::string formName, std::string target)
{
	std::cout << std::endl << "---- Creating form \"" << formName
		<< "\" with target \"" << target << "\":" << std::endl;
	Intern	lowlyIntern = Intern();
	Bureaucrat bigBoss("Big Boss Barry", 1);
	AForm *	form;
	try
	{
		form = lowlyIntern.makeForm(formName, target);
		bigBoss.signForm(*form);
		bigBoss.executeForm(*form);
		delete (form);
	}
	catch (std::exception & e)
	{
		std::cout << RED ": " << e.what() << RESET << std::endl;
	}
}

int	main(void)
{
	std::string const	shrubberyFormName = "shrubbery creation";
	std::string const	robotomyFormName = "robotomy request";
	std::string const	presidentialFormName = "presidential pardon";

	testInternFormCreation(shrubberyFormName, "Garden");
	testInternFormCreation(robotomyFormName, "Unsuspecting Customer");
	testInternFormCreation(presidentialFormName, "Jesus");
	testInternFormCreation("Bad Form Name", "Mr. X");
	testInternFormCreation("", "");	
	return (0);
}


