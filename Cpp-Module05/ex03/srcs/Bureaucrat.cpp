/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:36:56 by akhellad          #+#    #+#             */
/*   Updated: 2023/12/18 17:12:20 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

#include <iostream>

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade){}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name)
{
    if (!checkGrade(grade)) {
        throw;
    }
    this->_grade = grade;
}

bool Bureaucrat::checkGrade(int grade) const {
    if (grade < 1) {
        throw GradeTooHighException();
        return false;
    } else if (grade > 150) {
        throw GradeTooLowException();
        return false;
    }
    return true;
}

Bureaucrat::~Bureaucrat(){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->_grade = other._grade;
    }
    return *this;
}

std::string const &	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
    if (!checkGrade(_grade - 1)) {
        throw;
    }
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (!checkGrade(_grade + 1)) {
        throw;
    }
    _grade++;
}

void Bureaucrat::signForm(AForm& form) const{
    if (form.beSigned(*this)) {
        std::cout << _name << " signed " << form.getName() << std::endl;
    } else {
        std::cout << _name << " couldn't sign " << form.getName() << " because ";
        throw GradeTooLowException();
    }
}

void	Bureaucrat::executeForm(AForm & form) const
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executed " << form << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << *this << " couldn't execute " << form << " because: "
			<< e.what() << std::endl;
	}
	return ;
}

const char *	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat cannot outrank CEO: grade too low.");	
}

const char *	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat cannot sink to an intern's level: grade too high.");
}

std::ostream &	operator<<(std::ostream & os, Bureaucrat const & obj)
{
	os << "Bureaucrat \"" << obj.getName()
		<< "\" (grade: " << obj.getGrade() << ")";
	return (os);
}