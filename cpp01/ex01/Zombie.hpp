/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:57:58 by authomas          #+#    #+#             */
/*   Updated: 2025/12/29 15:53:49 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie
{
    public:
        Zombie();
        ~Zombie();
        void announce();
        void nameZombie(std::string _name);

    private:
    std::string name;
    
};

Zombie *zombieHorde(int N, std::string name);

#endif
