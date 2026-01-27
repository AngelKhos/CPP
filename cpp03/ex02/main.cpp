/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:02:41 by authomas          #+#    #+#             */
/*   Updated: 2026/01/27 17:00:23 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	FragTrap s1;
	FragTrap s2 = FragTrap("Patrick");
	FragTrap c1 = s1;
	FragTrap c2 = FragTrap("Michel");

	c1 = s2;

	std::cout << c1 << std::endl;
	std::cout << c2 << std::endl;
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	c2.attack(s2.getName());
	s2.takeDamage(c2.getAttackDamage());
	std::cout << s2 << std::endl;
	std::cout << c2 << std::endl;
	s2.attack(c2.getName());
	c2.takeDamage(s2.getAttackDamage());
	std::cout << s2 << std::endl;
	std::cout << c2 << std::endl;

	s2.highFivesGuys();

}