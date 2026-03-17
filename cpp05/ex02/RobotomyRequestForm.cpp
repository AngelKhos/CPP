/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:02:37 by authomas          #+#    #+#             */
/*   Updated: 2026/03/17 18:46:37 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), target("no one")
{
    std::cout << "Robotomy constructor called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("Robotomy", 72, 45), target(_target)
{
    std::cout << "Robotomy target constructor called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &_Form)
{
    *this = _Form;
    std::cout << "Robotomy copy constructor called" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    this->target = obj.target;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned())
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getExeGrade())
        throw AForm::GradeTooLowException();
    std::cout << "*Drilling noises, drilling noises*" << std::endl;
    if (rand() % 2 == 0)
        std::cout << target << " has been robotomized." << std::endl;
    else
        std::cout << "The robotomy failed. Try again." << std::endl;
}