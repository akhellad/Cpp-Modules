/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 23:32:54 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/31 23:37:28 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>

class Zombie {
public:
    Zombie(std::string name);
    ~Zombie();
    void announce() const;
private:
    std::string _name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
