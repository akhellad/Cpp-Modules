/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:28:51 by akhellad          #+#    #+#             */
/*   Updated: 2023/12/18 17:12:40 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_H
# define BUREAUCRAT_CLASS_H

# include "AForm.hpp"
# include <string>

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat(std::string const & name, int grade);
		Bureaucrat &	operator=(Bureaucrat const & src);
		~Bureaucrat(void);

		std::string const &	getName(void) const;
		int					getGrade(void) const;

    	void incrementGrade();
    	void decrementGrade();
    	bool checkGrade(int grade) const;

		void	signForm(AForm & form) const;
		void	executeForm(AForm & form) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

	private:
		Bureaucrat();
		std::string const	_name;
		int					_grade;

};

std::ostream &	operator<<(std::ostream & os, Bureaucrat const & bureaucrat);

#endif
