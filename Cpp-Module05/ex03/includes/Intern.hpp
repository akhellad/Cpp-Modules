/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:35:01 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/01 14:35:06 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_H
# define INTERN_CLASS_H

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include <string>

class Intern
{
	public:
		Intern(void);
		Intern(Intern const & src);
		~Intern(void);

		Intern &	operator=(Intern const & src);

		AForm *	makeForm(std::string formName, std::string target);

		class InvalidFormName : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

	private:
		typedef struct	sFormList
		{
			std::string const &	formName;
			AForm *	(*function)(std::string const &);
		}	formList;
};

#endif