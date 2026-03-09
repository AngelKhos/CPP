/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:31:35 by authomas          #+#    #+#             */
/*   Updated: 2026/03/09 23:16:33 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

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

        // pour creer une exception il faut faire une class <nom de l'exception>
        // qui herite de std::exception
        
        class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
            /*virtual pour que la prohaine exception puisse réécrire dessus
            apparemment toutes les exceptions ont "what()" en virtual
            faudra definir what t'a vu*/
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

