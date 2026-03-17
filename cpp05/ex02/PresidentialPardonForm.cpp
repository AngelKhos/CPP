/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:07:48 by authomas          #+#    #+#             */
/*   Updated: 2026/03/17 20:33:30 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5), target("no one")
{
    std::cout << "PresidentialPardon constructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("PresidentialPardon", 25, 5), target(_target)
{
    std::cout << "PresidentialPardon target constructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &_Form) : AForm("PresidentialPardon", 25, 5)
{
    *this = _Form;
    std::cout << "PresidentialPardon copy constructor called" << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardon destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
    this->target = obj.target;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
     if (!this->isSigned())
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getExeGrade())
        throw AForm::GradeTooLowException();

    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}