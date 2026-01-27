/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 12:53:36 by authomas          #+#    #+#             */
/*   Updated: 2026/01/27 15:39:53 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
    std::cout << "ScavTrap name constructor called" << std::endl;
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &_obj) : ClapTrap(_obj)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    name = _obj.name;
    hit_points = _obj.hit_points;
    energy_points = _obj.energy_points;
    attack_damage = _obj.attack_damage;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &_obj)
{
    this->name = _obj.name;
    this->hit_points = _obj.hit_points;
    this->energy_points = _obj.energy_points;
    this->attack_damage = _obj.attack_damage;

    return (*this);
}

void ScavTrap::attack(const std::string &target)
{
    if (energy_points > 0 && hit_points > 0)
    {
        std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
        energy_points--;
    }
    else if (energy_points == 0)
        std::cout << "ScavTrap " << name << " tried to attack " << target << " but has no energy points left :(" << std::endl;
    else if (hit_points <= 0)
        std::cout << "ScavTrap " << name << " tried to attack " << target << " but has no hit points left :(" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " is now in Gate Keeper Mode" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const ScavTrap &_Scav)
{
    out << _Scav.getName() << ": HP " << _Scav.getHitPoint() << " EP " << _Scav.getEnergyPoint() << std::endl;
    return (out);
}

