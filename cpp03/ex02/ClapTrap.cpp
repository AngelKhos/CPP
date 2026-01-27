/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:02:38 by authomas          #+#    #+#             */
/*   Updated: 2026/01/27 13:38:14 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap default constructor called" << std::endl;
    hit_points = 10;
    energy_points = 10;
    attack_damage = 0;
}

ClapTrap::ClapTrap(std::string _name): name(_name)
{
    std::cout << "ClapTrap name constructor called" << std::endl;
    hit_points = 10;
    energy_points = 10;
    attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &_obj)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    name = _obj.name;
    hit_points = _obj.hit_points;
    energy_points = _obj.energy_points;
    attack_damage = _obj.attack_damage;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &_obj)
{
    this->name = _obj.name;
    this->hit_points = _obj.hit_points;
    this->energy_points = _obj.energy_points;
    this->attack_damage = _obj.attack_damage;

    return (*this);
}

std::string ClapTrap::getName() const
{
    return (name);
}

int ClapTrap::getEnergyPoint() const
{
    return (energy_points);
}

int ClapTrap::getHitPoint() const
{
    return (hit_points);
}

int ClapTrap::getAttackDamage() const
{
    return (attack_damage);
}

void ClapTrap::attack(const std::string &target)
{
    if (energy_points > 0 && hit_points > 0)
    {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
        energy_points--;
    }
    else if (energy_points == 0)
        std::cout << "ClapTrap " << name << " tried to attack " << target << " but has no energy points left :(" << std::endl;
    else if (hit_points <= 0)
        std::cout << "ClapTrap " << name << " tried to attack " << target << " but has no hit points left :(" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << name << " takes " << amount << " damage!" << std::endl;
    hit_points -= amount;
    if (hit_points <= 0)
        std::cout << "ClapTrap " << name << " can't take more damage!" << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energy_points > 0)
    {
        std::cout << "ClapTrap " << name << " repairs itself, gaining " << amount << " hit points!" << std::endl;
        hit_points += amount;
        energy_points--;
    }
    else
        std::cout << "ClapTrap " << name << " tried to repair but has no energy points left :(" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const ClapTrap &_Clap)
{
    out << _Clap.getName() << ": HP " << _Clap.getHitPoint() << " EP " << _Clap.getEnergyPoint() << std::endl;
    return (out);
}