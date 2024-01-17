/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:02:48 by akhellad          #+#    #+#             */
/*   Updated: 2023/12/18 16:23:22 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	AFORM_CLASS_H
# define AFORM_CLASS_H

# include "Bureaucrat.hpp"
# include <string>

class Bureaucrat;

class AForm
{
	public:
		AForm(AForm const & src);
		AForm(std::string const & name, int const gradeToSign, int const gradeToExecute);
		virtual ~AForm(void);

		AForm &	operator=(AForm const & src);

		std::string const &	getName(void) const;
		bool				isSigned(void) const;
		int					getGradeRequiredToSign(void) const;
		int					getGradeRequiredToExecute(void) const;

		bool	beSigned(Bureaucrat const & bureaucrat);
		void	execute(Bureaucrat const & bureaucrat) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

		class AlreadySignedException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

		class NotSignedException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

	protected:
		virtual void	beExecuted(void) const = 0;

	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeRequiredToSign;
		int const			_gradeRequiredToExecute;
		AForm(void);
};

std::ostream &	operator<<(std::ostream & os, AForm const & obj);

#endif

