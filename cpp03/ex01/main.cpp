/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:02:41 by authomas          #+#    #+#             */
/*   Updated: 2026/01/27 13:39:41 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int	main(void)
{
	ScavTrap s1;
	ScavTrap s2 = ScavTrap("Patrick");
	ScavTrap c1 = s1;
	ScavTrap c2 = ScavTrap("Michel");

	c1 = s2;

	std::cout << c1 << std::endl;
	std::cout << c2 << std::endl;
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	c2.attack(s2.getName());
	s2.takeDamage(c2.getHitPoint());
	std::cout << s2 << std::endl;
	std::cout << c2 << std::endl;
	s2.attack(c2.getName());
	c2.takeDamage(s2.getHitPoint());
	std::cout << s2 << std::endl;
	std::cout << c2 << std::endl;

	s2.guardGate();

}