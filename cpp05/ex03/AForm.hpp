/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:08:23 by authomas          #+#    #+#             */
/*   Updated: 2026/03/14 17:39:40 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:

        AForm();
        AForm(std::string _name);
        AForm(int _sGrade, int _eGrade);
        AForm(std::string _name, int _sGrade, int _eGrade);
        AForm(const AForm &_obj);
        AForm &operator=(const AForm &obj);
        virtual ~AForm();

        std::string getName() const;
        int getSignGrade() const;
        int getExeGrade() const;
        bool isSigned() const;

        void beSigned(Bureaucrat &_Slave);
        virtual void execute(Bureaucrat const &executor) const = 0;
    
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

        class NotSignedException : public std::exception
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

std::ostream &operator<<(std::ostream &out, const AForm &_Form);

#endif