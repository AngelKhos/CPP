/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 12:47:23 by authomas          #+#    #+#             */
/*   Updated: 2025/12/24 12:48:22 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include <iostream>

class Contact 
{
    public:
        Contact();
        void fill_contact(std::string first, std::string last,
             std::string nick, std::string phone, std::string secret);
        std::string get_fname();
        std::string get_lname();
        std::string get_nick();
        std::string get_phone();
        std::string get_secret();


    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
};

#endif