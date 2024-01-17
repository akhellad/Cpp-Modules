/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:03:32 by akhellad          #+#    #+#             */
/*   Updated: 2023/12/18 17:09:59 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

#include <iostream>
#include <cstdlib>

AForm::AForm(AForm const & src) :	_name(src._name),
									_isSigned(false),
									_gradeRequiredToSign(src._gradeRequiredToSign),
									_gradeRequiredToExecute(src._gradeRequiredToExecute) {}

AForm::AForm(std::string const & name, int const gradeToSign, int const gradeToExecute)
			:	_name(name),
				_isSigned(false),
				_gradeRequiredToSign(gradeToSign),
				_gradeRequiredToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    };
}

AForm::~AForm(void){}

AForm &	AForm::operator=(AForm const & src)
{
	this->_isSigned = src._isSigned;
	return (*this);
}

std::string const &	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::isSigned(void) const
{
	return (this->_isSigned);
}

int	AForm::getGradeRequiredToSign(void) const
{
	return (this->_gradeRequiredToSign);
}

int	AForm::getGradeRequiredToExecute(void) const
{
	return (this->_gradeRequiredToExecute);
}

bool AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= _gradeRequiredToSign) {
        _isSigned = true;
        return true;
    }
    return false;
}

void	AForm::execute(Bureaucrat const & bureaucrat) const
{
	if (this->_isSigned == false)
		throw (AForm::NotSignedException());
	if (bureaucrat.getGrade() > this->_gradeRequiredToExecute)
		throw (AForm::GradeTooLowException());
	this->beExecuted();
	return ;
}

const char *	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high for form.");
}

const char *	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low for form.");
}

const char *	AForm::AlreadySignedException::what(void) const throw()
{
	return ("Form is already signed.");
}

const char *	AForm::NotSignedException::what(void) const throw()
{
	return ("Form has not been signed.");
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No") << ", Sign Grade: " << form.getGradeRequiredToSign() << ", Exec Grade: " << form.getGradeRequiredToExecute();
    return os;
}

