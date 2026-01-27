/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:02:41 by authomas          #+#    #+#             */
/*   Updated: 2026/01/26 12:34:59 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	ClapTrap	c1;
	ClapTrap	c2 = ClapTrap(c1);
	ClapTrap	c3;
	ClapTrap	c4 = ClapTrap("Patrick");

	c3 = c2;
	std::cout << c1 << std::endl;
	std::cout << c2 << std::endl;
	std::cout << c3 << std::endl;
	std::cout << c4 << std::endl;

	c4.beRepaired(5);
	c4.takeDamage(1);
	c4.attack("michel");
	std::cout << c4 << std::endl;
	c4.takeDamage(15);
	std::cout << c4 << std::endl;
	c4.takeDamage(1);
	c4.beRepaired(5);
	c4.attack("michel");
}