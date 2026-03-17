/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:08:19 by authomas          #+#    #+#             */
/*   Updated: 2026/03/13 18:13:27 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Default Form"),signedVar(false), signGrade(150), exeGrade(150)
{
    std::cout << "Form Default constructor called" << std::endl;
}
Form::Form(std::string _name) : name(_name) ,signedVar(false), signGrade(150), exeGrade(150)
{
    std::cout << "Form Name constructor called" << std::endl;
}
Form::Form(int _sGrade, int _eGrade) : name("Default Form"), signedVar(false), signGrade(_sGrade), exeGrade(_eGrade)
{
    std::cout << "Form Grade constructor called" << std::endl;
    if (_sGrade < 1 || _eGrade < 1)
        throw Form::GradeTooHighException();
    else if (_sGrade > 150 || _eGrade > 150)
        throw Form::GradeTooLowException();
}
Form::Form(std::string _name, int _sGrade, int _eGrade) : name(_name), signedVar(false), signGrade(_sGrade), exeGrade(_eGrade)
{
     std::cout << "Form Name and Grade constructor called" << std::endl;
    if (_sGrade < 1 || _eGrade < 1)
        throw Form::GradeTooHighException();
    else if (_sGrade > 150 || _eGrade > 150)
        throw Form::GradeTooLowException();
}
Form::Form(const Form &_obj) : name(_obj.name), signedVar(_obj.signedVar), signGrade(_obj.signGrade), exeGrade(_obj.exeGrade)
{
    std::cout << "Form Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &obj)
{
    if (this != &obj)
        this->signedVar = obj.isSigned();
    return (*this);
}
Form::~Form()
{
    std::cout << "Form Destructor called" << std::endl;
}

std::string Form::getName() const
{
    return(name);
}
int Form::getSignGrade() const
{
    return(signGrade);
}
int Form::getExeGrade() const
{
    return(exeGrade);
}
bool Form::isSigned() const
{
    return(signedVar);
}

void Form::beSigned(Bureaucrat &_Slave)
{
    if (_Slave.getGrade() > signGrade)
        throw Form::GradeTooLowException();
    signedVar = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, const Form &_Form)
{
    out << "Form <" << _Form.getName() << "> : is it signed? " << _Form.isSigned() << std::endl 
        << "Can be signed by :" << _Form.getSignGrade() << " or higher" << std::endl
        << "Can be executed by :" << _Form.getExeGrade() << " or higher" << std::endl;
    return (out);
}