/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:08:19 by authomas          #+#    #+#             */
/*   Updated: 2026/03/13 18:13:27 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("Default AForm"),signedVar(false), signGrade(150), exeGrade(150)
{
    std::cout << "AForm Default constructor called" << std::endl;
}
AForm::AForm(std::string _name) : name(_name) ,signedVar(false), signGrade(150), exeGrade(150)
{
    std::cout << "AForm Name constructor called" << std::endl;
}
AForm::AForm(int _sGrade, int _eGrade) : name("Default AForm"), signedVar(false), signGrade(_sGrade), exeGrade(_eGrade)
{
    std::cout << "AForm Grade constructor called" << std::endl;
    if (_sGrade < 1 || _eGrade < 1)
        throw AForm::GradeTooHighException();
    else if (_sGrade > 150 || _eGrade > 150)
        throw AForm::GradeTooLowException();
}
AForm::AForm(std::string _name, int _sGrade, int _eGrade) : name(_name), signedVar(false), signGrade(_sGrade), exeGrade(_eGrade)
{
     std::cout << "AForm Name and Grade constructor called" << std::endl;
    if (_sGrade < 1 || _eGrade < 1)
        throw AForm::GradeTooHighException();
    else if (_sGrade > 150 || _eGrade > 150)
        throw AForm::GradeTooLowException();
}
AForm::AForm(const AForm &_obj) : name(_obj.name), signedVar(_obj.signedVar), signGrade(_obj.signGrade), exeGrade(_obj.exeGrade)
{
    std::cout << "AForm Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &obj)
{
    if (this != &obj)
        this->signedVar = obj.isSigned();
    return (*this);
}
AForm::~AForm()
{
    std::cout << "AForm Destructor called" << std::endl;
}

std::string AForm::getName() const
{
    return(name);
}
int AForm::getSignGrade() const
{
    return(signGrade);
}
int AForm::getExeGrade() const
{
    return(exeGrade);
}
bool AForm::isSigned() const
{
    return(signedVar);
}

void AForm::beSigned(Bureaucrat &_Slave)
{
    if (_Slave.getGrade() > signGrade)
        throw AForm::GradeTooLowException();
    signedVar = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char* AForm::NotSignedException::what() const throw()
{
    return ("Form not signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &_Form)
{
    out << "AForm <" << _Form.getName() << "> : is it signed? " << _Form.isSigned() << std::endl 
        << "Can be signed by :" << _Form.getSignGrade() << " or higher" << std::endl
        << "Can be executed by :" << _Form.getExeGrade() << " or higher" << std::endl;
    return (out);
}