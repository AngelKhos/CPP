/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 00:43:50 by authomas          #+#    #+#             */
/*   Updated: 2026/03/18 01:37:01 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &_intern)
{
    (void)_intern;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &_intern)
{
    (void)_intern;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeShruberry(std::string target)
{
    return (new ShrubberyCreationForm(target));
}
AForm *Intern::makePresidential(std::string target)
{
    return (new PresidentialPardonForm(target));
}
AForm *Intern::makeRobotomy(std::string target)
{
    return (new RobotomyRequestForm(target));
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return ("Form not found");
}


AForm *Intern::makeForm(std::string name, std::string target)
{
    std::string formNames[3] = {"Shrubbery", "Presidential", "Robotomy"};
    AForm *(*formList[3])(std::string) = {&Intern::makeShruberry, &Intern::makePresidential, &Intern::makeRobotomy};
    
    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return(formList[i](target));
        }
    }
    throw Intern::FormNotFoundException();
}
