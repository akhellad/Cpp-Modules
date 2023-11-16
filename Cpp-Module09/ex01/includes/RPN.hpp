/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:30:06 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/09 10:33:04 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    int evaluateExpression(const std::string& expression);

private:
    std::stack<int> _stack;
    bool isOperator(const char& c) const;
    int performOperation(const char& op, int operand1, int operand2);
    int toInt(const std::string& str);
};

#endif // RPN_HPP

