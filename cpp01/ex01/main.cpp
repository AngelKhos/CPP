/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:01:44 by authomas          #+#    #+#             */
/*   Updated: 2025/12/29 15:56:25 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main()
{
    Zombie *zombie1 = zombieHorde(5, "Luc");
    for (int i = 0; i < 5; i++)
        zombie1[i].announce();
    delete[] zombie1;

    return (0);
}