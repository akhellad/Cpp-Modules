/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:27:57 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/01 14:17:52 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm(std::string const & target);
		~PresidentialPardonForm(void);

		PresidentialPardonForm &	operator=(PresidentialPardonForm const & src);

		std::string const &	getTarget(void) const;

		void	beExecuted(void) const;

		static int const	gradeToSign = 25;
		static int const	gradeToExecute = 5;

	private:
		std::string	_target;
};

#endif
