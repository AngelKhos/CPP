/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:03:01 by authomas          #+#    #+#             */
/*   Updated: 2026/03/17 20:36:08 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), target("no one")
{
    std::cout << "shrubbery constructor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("Shrubbery", 145, 137), target(_target)
{
    std::cout << "shrubbery target constructor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &_Form) : AForm("Shrubbery", 145, 137)
{
    *this = _Form;
    std::cout << "shrubbery copy constructor called" << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "shrubbery destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    this->target = obj.target;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
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
                << "     /~~   ~~\\    " << std::endl
                << "  /~~         ~~\\ " << std::endl
                << " {               }" << std::endl
                << "  \\  _-     -_  / " << std::endl
                << "    ~  \\\\ //  ~   " << std::endl
                << " _- -   | | _- _  " << std::endl
                << "   _ -  | |   -_  " << std::endl
                << "       // \\\\      " << std::endl;
    }
}