/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 00:38:44 by authomas          #+#    #+#             */
/*   Updated: 2026/03/18 01:33:04 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &_intern);
        Intern &operator=(const Intern &_intern);
        ~Intern();

        AForm *makeForm(std::string name, std::string target);

        class FormNotFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
        
    private:
        static AForm *makeShruberry(std::string target);
        static AForm *makePresidential(std::string target);
        static AForm *makeRobotomy(std::string target);
};

#endif