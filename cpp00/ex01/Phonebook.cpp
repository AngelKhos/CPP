/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:17:56 by authomas          #+#    #+#             */
/*   Updated: 2025/12/29 14:29:08 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

Phonebook::Phonebook()
{
    index = 0;
    contacts_filled = 0;
}

int Phonebook::add_contact()
{
    std::string first;
    std::string last;
    std::string nick;
    std::string phone;
    std::string secret;

    std::cout << "Please enter first name >";
    if (!std::getline(std::cin, first))
    {
        std::cout << std::endl;
        return (EXIT_FAILURE);
    }
    std::cout << "Enter last name >";
    if (!std::getline(std::cin, last))
    {
        std::cout << std::endl;
        return (EXIT_FAILURE);
    }
    std::cout << "Enter nickname >";
    if (!std::getline(std::cin, nick))
    {
        std::cout << std::endl;
        return (EXIT_FAILURE);
    }
    std::cout << "Enter phone number >";
    if (!std::getline(std::cin, phone))
    {
        std::cout << std::endl;
        return (EXIT_FAILURE);
    }
    std::cout << "Please give me the darkest secret >";
    if (!std::getline(std::cin, secret))
    {
        std::cout << std::endl;
        return (EXIT_FAILURE);
    }

    if (first == "" || last == "" || nick == "" || phone == "" || secret == "")
    {
        std::cout << "One field is empty, please try again" << std::endl;
        return (EXIT_SUCCESS);
    }

    contacts[index].fill_contact(first, last, nick, phone, secret);
    if (contacts_filled < 8)
        contacts_filled++;
    index = (index + 1) % 8;

    std::cout << "This contact has been added." << std::endl;
    return (EXIT_SUCCESS);
}

int Phonebook::get_filled()
{
    return contacts_filled;
}

std::string str_truncate(std::string str)
{
    if (str.length() <= 10)
        return str;
    return str.substr(0, 9) + ".";
}

void Phonebook::display_all()
{
    std::cout << std::setw(10) << "Index" << "|" 
    << std::setw(10) << "First" << "|"
    << std::setw(10) << "Last" << "|"
    << std::setw(10) << "Nickname" << std::endl;
    for(int i = 0; i < contacts_filled; i++)
    {
        std::cout << std::setw(10) << i << "|"
        << std::setw(10) << str_truncate(contacts[i].get_fname()) << "|" 
        << std::setw(10) << str_truncate(contacts[i].get_lname()) << "|"
        << std::setw(10) << str_truncate(contacts[i].get_nick()) << std::endl;

    }
}

void Phonebook::display_one(int i)
{
    if (i < 0 || i >= contacts_filled)
    {
        std::cout << "Invalid index, try again." << std::endl;
        return ;
    }
    std::cout << "First name: " << contacts[i].get_fname() << std::endl;
    std::cout << "Last name: " << contacts[i].get_lname() << std::endl;
    std::cout << "Nickname: " << contacts[i].get_nick() << std::endl;
    std::cout << "Phone number: " << contacts[i].get_phone() << std::endl;
    std::cout << "Darkest secret: " << contacts[i].get_secret() << std::endl;
}