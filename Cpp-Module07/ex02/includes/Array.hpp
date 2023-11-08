/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:25:01 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/07 10:28:08 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <cstddef>

template <typename T>
class Array {
public:
    Array();
    Array(unsigned int n);
    Array(const Array<T> &other); 
    Array<T>& operator=(const Array<T> &other);

    ~Array();

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    unsigned int size() const;

private:
    T *data; 
    unsigned int length;
};

# include "../srcs/Array.tpp"

#endif
