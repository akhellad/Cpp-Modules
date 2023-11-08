/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:17:40 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/07 12:35:08 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span {
public:
    Span(unsigned int n);
    ~Span();
    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    template <typename InputIterator>
    void addRange(InputIterator first, InputIterator last);
    const std::vector<int>& getNumbers() const {
        return _numbers;
    }
    
private:
    unsigned int _N;
    std::vector<int> _numbers;
};

#include "../srcs/span.tpp"

#endif
