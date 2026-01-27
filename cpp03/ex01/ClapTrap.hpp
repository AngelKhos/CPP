/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:56:51 by authomas          #+#    #+#             */
/*   Updated: 2026/01/26 12:53:03 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(std::string _name);
        ClapTrap(const ClapTrap &_obj);
        ClapTrap &operator=(const ClapTrap &obj);
        ~ClapTrap();

        std::string getName() const; 
        int getEnergyPoint() const;
        int getHitPoint() const;
        
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    private:
        std::string name;
        int hit_points;
        int energy_points;
        int attack_damage;
};

std::ostream &operator<<(std::ostream &out, const ClapTrap &_Clap);

#endif