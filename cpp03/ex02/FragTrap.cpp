/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:43:14 by authomas          #+#    #+#             */
/*   Updated: 2026/01/27 16:57:57 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    hit_points = 100;
    energy_points = 100;
    attack_damage =30;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
    std::cout << "FragTrap name constructor called" << std::endl;
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &_obj) : ClapTrap(_obj)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    name = _obj.name;
    hit_points = _obj.hit_points;
    energy_points = _obj.energy_points;
    attack_damage = _obj.attack_damage;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &_obj)
{
    this->name = _obj.name;
    this->hit_points = _obj.hit_points;
    this->energy_points = _obj.energy_points;
    this->attack_damage = _obj.attack_damage;

    return (*this);
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " is requesting a high five!" << std::endl;
}
std::ostream &operator<<(std::ostream &out, const FragTrap &_Frag)
{
    out << _Frag.getName() << ": HP " << _Frag.getHitPoint() << " EP " << _Frag.getEnergyPoint() << std::endl;
    return (out);
}

