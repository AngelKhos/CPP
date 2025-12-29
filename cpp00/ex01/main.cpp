/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 12:48:59 by authomas          #+#    #+#             */
/*   Updated: 2025/12/29 14:28:39 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <sstream>
#include <cstdlib>
#include <iostream>

int main(void)
{
    Phonebook phonebook;
    std::string str;

    while (str != "EXIT")
    {
        std::cout << "Please enter a command > ";
        if (!std::getline(std::cin , str))
        {
            std::cout << std::endl;
            return (EXIT_FAILURE);
        }
        if (str == "ADD")
        {
            if (phonebook.add_contact() == EXIT_FAILURE)
            {
                std::cout << "Something went wrong, exiting..." << std::endl;
                return (EXIT_FAILURE);
            }
        }
        else if (str == "SEARCH")
        {
            if (phonebook.get_filled() == 0)
                std::cout << "The phonebook is empty" << std::endl;
            else
            {
                std::string index;
                phonebook.display_all();
                std::cout << "Please pick an index >";
                if (!std::getline(std::cin, index))
                {
                    std::cout << std::endl;
                    return (EXIT_FAILURE);
                }
                int i = 0;
                std::stringstream s;
                s << index;
                if (!(s >> i))
                    std::cout << "Wrong input, try again" << std::endl;
                else
                    phonebook.display_one(i);
            }
        }
    }
    std::cout << "Bye!" << std::endl;
    return (EXIT_SUCCESS);
}
