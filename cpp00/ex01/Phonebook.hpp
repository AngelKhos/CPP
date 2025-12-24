/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:05:03 by authomas          #+#    #+#             */
/*   Updated: 2025/12/24 18:03:15 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class Phonebook
{
    public:
        Phonebook();
        int add_contact();
        void display_all();
        void display_one(int i);
        int get_filled();
    private:
        Contact contacts[8];
        int index;
        int contacts_filled;
};
#endif