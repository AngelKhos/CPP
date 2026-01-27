/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:44:40 by authomas          #+#    #+#             */
/*   Updated: 2026/01/27 15:48:09 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <string>

class FragTrap: public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string _name);
        FragTrap(const FragTrap &_obj);
        FragTrap &operator=(const FragTrap &obj);
        ~FragTrap();
        
        void highFivesGuys();
};

std::ostream &operator<<(std::ostream &out, const FragTrap &_Scav);

#endif