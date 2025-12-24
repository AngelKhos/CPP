/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 12:51:40 by authomas          #+#    #+#             */
/*   Updated: 2025/12/24 15:15:29 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){}

void Contact::fill_contact(std::string first, std::string last,
             std::string nick, std::string phone, std::string secret)
{
    first_name = first;
    last_name = last;
    nickname = nick;
    phone_number = phone;
    darkest_secret = secret;
}

std::string Contact::get_fname()
{
    return first_name;
}

std::string Contact::get_lname()
{
    return last_name;
}

std::string Contact::get_nick()
{
    return nickname;
}

std::string Contact::get_phone()
{
    return phone_number;
}

std::string Contact::get_secret()
{
    return darkest_secret;
}