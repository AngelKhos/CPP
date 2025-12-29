/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:57:58 by authomas          #+#    #+#             */
/*   Updated: 2025/12/29 15:35:27 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie
{
    public:
        Zombie(std::string name);
        ~Zombie();
        void announce();

    private:
    std::string name;
    
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
