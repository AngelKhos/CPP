/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:54:04 by authomas          #+#    #+#             */
/*   Updated: 2026/01/02 18:15:27 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H

#include <string>

class Harl
{
    public:
        Harl();
        void complain( std::string level );

    private:
        void debug();
        void info();
        void warning();
        void error();
        void (Harl::*ptr[4])(void);
};

#endif