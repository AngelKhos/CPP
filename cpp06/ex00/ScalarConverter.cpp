/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 01:53:47 by authomas          #+#    #+#             */
/*   Updated: 2026/03/18 03:24:15 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Scalarconverter.hpp"
#include <iostream>
#include <cstdlib>

void ScalarConverter::convert(std::string input)
{
    char charValue;
    int intValue;
     double doubleValue;
     float floatValue;
    
    if (input.length() == 1 && !isdigit(input[0]))
    {
        charValue = input[0];
        intValue = int(charValue);
        floatValue = float(charValue);
        doubleValue = double(charValue);
    }
    else if ((input[0] == '-' && input.find_first_not_of("0123456789", 1)) || input.find_first_not_of("0123456789"))
    {
        intValue = atoi(input.c_str());
        charValue = char(intValue);
        doubleValue = double(intValue);
        floatValue = float(intValue);
    }
    
    // 1- detect input type
    // int <-- is only number (can contain -)
    // float <-- number, end with f, contains . (can contain -)
    // double <-- number, contains . (can contain -)
    
    //2- convert from string to type
        
        
    //3- convert EXPLICITELY from this to other types

    //4- display

    std::cout << "Char : " << charValue << std::endl;
    std::cout << "Int : " << intValue << std::endl;
    std::cout << "Float : " << floatValue << std::endl;
    std::cout << "Double : " << doubleValue << std::endl;
}