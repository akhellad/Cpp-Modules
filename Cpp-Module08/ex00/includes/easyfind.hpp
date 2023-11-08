/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:59:56 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/07 11:02:46 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator it = container.begin();
    typename T::iterator end = container.end();

    while (it != end) {
        if (*it == value) {
            return it;
        }
        ++it;
    }

    throw std::runtime_error("Value not found");
}

#endif

