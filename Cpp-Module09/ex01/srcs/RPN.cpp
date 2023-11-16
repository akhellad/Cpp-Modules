/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:33:15 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/09 10:33:44 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"
#include <sstream>
#include <iostream>
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    _stack = other._stack;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(const char& c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::performOperation(const char& op, int operand1, int operand2) {
    switch (op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': 
            if (operand2 == 0) throw std::runtime_error("Division by zero");
            return operand1 / operand2;
        default: throw std::runtime_error("Unknown operator");
    }
}

int RPN::toInt(const std::string& str) {
    std::istringstream iss(str);
    int num;
    iss >> num;
    return num;
}

int RPN::evaluateExpression(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isOperator(token[0]) && token.length() == 1) {
            if (_stack.size() < 2) throw std::runtime_error("Invalid expression");
            int operand2 = _stack.top(); _stack.pop();
            int operand1 = _stack.top(); _stack.pop();
            _stack.push(performOperation(token[0], operand1, operand2));
        } else {
            _stack.push(toInt(token));
        }
    }

    if (_stack.size() != 1) throw std::runtime_error("Invalid expression");
    return _stack.top();
}
