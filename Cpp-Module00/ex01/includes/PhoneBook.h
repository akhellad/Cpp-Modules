/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:47:53 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/31 18:06:13 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.h"

class PhoneBook
{
	public :
		PhoneBook(void);
		void	add_contact(void);
		void	search_contact(void) const;
	private :
		Contact	_contacts[8];
		int		_nb_contacts;
		int		_index;
};

#endif