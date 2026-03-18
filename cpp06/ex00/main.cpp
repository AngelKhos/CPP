/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 01:55:16 by authomas          #+#    #+#             */
/*   Updated: 2026/03/18 02:00:15 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Scalarconverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    
    std::string input(av[1]);
    
    ScalarConverter::convert(input);
    
    return (0);
}