/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:56:51 by authomas          #+#    #+#             */
/*   Updated: 2026/01/27 13:34:39 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <string>

class ScavTrap: public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string _name);
        ScavTrap(const ScavTrap &_obj);
        ScavTrap &operator=(const ScavTrap &obj);
        ~ScavTrap();
        
        void attack(const std::string &target);
        void guardGate();
};

std::ostream &operator<<(std::ostream &out, const ScavTrap &_Scav);

#endif