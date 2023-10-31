/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:02:48 by akhellad          #+#    #+#             */
/*   Updated: 2023/10/31 20:32:59 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
    Form(const std::string& name, int signGrade, int execGrade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    const std::string& getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    bool beSigned(const Bureaucrat& bureaucrat);

private:
    const std::string name;
    bool sign;
    const int signGrade;    // Ajoutez ceci
    const int execGrade;    // Ajoutez ceci
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
