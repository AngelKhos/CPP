/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 16:15:53 by authomas          #+#    #+#             */
/*   Updated: 2025/12/30 17:48:04 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string _name):name(_name),weapon(NULL){}

void HumanB::attack()
{
    std::cout << name << " attacks with their " << weapon->getType() << std::endl; 
}

void HumanB::setWeapon(Weapon &_weapon)
{
    weapon = &_weapon;
}