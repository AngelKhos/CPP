/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:08:23 by authomas          #+#    #+#             */
/*   Updated: 2026/03/11 12:40:33 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:

        Form();
        Form(std::string _name);
        Form(int _sGrade, int _eGrade);
        Form(std::string _name, int _sGrade, int _eGrade);
        Form(const Form &_obj);
        Form &operator=(const Form &obj);
        ~Form();

        std::string getName() const;
        int getSignGrade() const;
        int getExeGrade() const;
        bool isSigned() const;

        void beSigned(Bureaucrat &_Slave);
    
        class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
        
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

    private:
        const std::string name;
        bool signedVar;
        const int signGrade;
        const int exeGrade;
};

std::ostream &operator<<(std::ostream &out, const Form &_Form);

#endif