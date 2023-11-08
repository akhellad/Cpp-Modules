/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:23:33 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/07 12:29:22 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP
#define SPAN_TPP

template <typename InputIterator>
void Span::addRange(InputIterator first, InputIterator last) {
    int count = std::distance(first, last);
    
    if (_numbers.size() + count > _N) {
        throw std::runtime_error("Not enough space to add the range");
    }
    
    while (first != last) {
        addNumber(*first);
        ++first;
    }
}

#endif
