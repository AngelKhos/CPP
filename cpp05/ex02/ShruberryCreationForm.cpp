/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:03:01 by authomas          #+#    #+#             */
/*   Updated: 2026/03/17 17:13:11 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShruberryCreationForm::ShruberryCreationForm() : AForm("Shrubbery", 145, 137), target("no one")
{
    std::cout << "shrubbery constructor called" << std::endl;
}
ShruberryCreationForm::ShruberryCreationForm(std::string _target) : AForm("Shrubbery", 145, 137), target(_target)
{
    std::cout << "shrubbery target constructor called" << std::endl;
}
ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm &_Form)
{
    *this = _Form;
    std::cout << "shrubbery copy constructor called" << std::endl;
}
ShruberryCreationForm::~ShruberryCreationForm()
{
    std::cout << "shrubbery destructor called" << std::endl;
}

ShruberryCreationForm &ShruberryCreationForm::operator=(const ShruberryCreationForm &obj)
{
    this->target = obj.target;
    return (*this);
}

void ShruberryCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned())
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getExeGrade())
        throw AForm::GradeTooLowException();
    std::string filename(target + "_shrubbery");
    std::ofstream outfile(filename.c_str());
    if (outfile.is_open())
    {
        outfile << "        _-_       " << std::endl
                << "     /~~   ~~\    " << std::endl
                << "  /~~         ~~\ " << std::endl
                << " {               }" << std::endl
                << "  \  _-     -_  / " << std::endl
                << "    ~  \\ //  ~   " << std::endl
                << " _- -   | | _- _  " << std::endl
                << "   _ -  | |   -_  " << std::endl
                << "       // \\      " << std::endl;
    }
}