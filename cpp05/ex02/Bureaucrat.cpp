/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:39:23 by authomas          #+#    #+#             */
/*   Updated: 2026/05/27 17:37:18 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(150)
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name) : name(_name), grade(150)
{
    std::cout << "Bureaucrat Name constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(int _grade) : name("Bureaucrat")
{
    std::cout << "Bureaucrat Grade constructor called" << std::endl;
    
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        grade = _grade;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name)
{
    std::cout << "Bureaucrat Name and grade constructor called" << std::endl;
    
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        grade = _grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat &_obj) : name(_obj.name)
{
    *this = _obj;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    if (grade != obj.grade)
        this->grade = obj.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return (name);
}
int Bureaucrat::getGrade() const
{
    return (grade);
}

void Bureaucrat::promote()
{
    if (grade == 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}
void Bureaucrat::demote()
{
    if (grade == 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

void Bureaucrat::signForm(AForm &_Form)
{
    if (_Form.isSigned())
    {
        std::cout << _Form.getName() << " is already signed" << std::endl;
        return ;
    }
    try
    {
        _Form.beSigned(*this);
        if (_Form.isSigned())
            std::cout << name << " signed " << _Form.getName() << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cout << name << " couldn't sign " << _Form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) const 
{
    try
    {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &_Slave)
{
    out << _Slave.getName() << ", bureaucrat grade " << _Slave.getGrade() << ".";
    return (out);
}