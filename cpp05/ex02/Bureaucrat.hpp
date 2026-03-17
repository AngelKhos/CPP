/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:31:35 by authomas          #+#    #+#             */
/*   Updated: 2026/03/11 12:40:55 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(std::string _name);
        Bureaucrat(int _grade);
        Bureaucrat(std::string _name, int _grade);
        Bureaucrat(const Bureaucrat &_obj);
        Bureaucrat &operator=(const Bureaucrat &obj);
        ~Bureaucrat();
        
        std::string getName() const;
        int getGrade() const; 

        void promote();
        void demote();

        void signForm(Form &_Form);
        
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
        int grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &_Slave);

#endif