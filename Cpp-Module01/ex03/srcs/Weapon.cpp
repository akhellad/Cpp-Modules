/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 02:32:59 by akhellad          #+#    #+#             */
/*   Updated: 2023/09/01 02:33:34 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.h"

Weapon::Weapon(std::string type) : _type(type) {}

const std::string& Weapon::getType() const {
    return _type;
}

void Weapon::setType(std::string type) {
    _type = type;
}