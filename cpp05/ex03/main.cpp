/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 23:22:12 by authomas          #+#    #+#             */
/*   Updated: 2026/03/18 01:37:32 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void)
{
    try {
		Bureaucrat bob("Bob", 1);
		Bureaucrat patric("Patric", 100);

		Intern Intern;

		AForm *paper = Intern.makeForm("Shrubbery", "tree");
		AForm *morePaper = Intern.makeForm("Robotomy", "bobby");
		AForm *moreAndMorePaper = Intern.makeForm("Presidential", "criminal");
		
		std::cout << "=============" << std::endl;
		bob.signForm(*paper);
		bob.executeForm(*paper);
		std::cout << "====paper^=====" << std::endl;
		bob.signForm(*morePaper);
		bob.executeForm(*morePaper);
		std::cout << "====morePaper^=====" << std::endl;
		bob.signForm(*moreAndMorePaper);
		bob.executeForm(*moreAndMorePaper);
		std::cout << "====moreAndMorePaper^=====" << std::endl;

		delete paper;
		delete morePaper;
		delete moreAndMorePaper;
		
		AForm *fakePaper = Intern.makeForm("making noodels", "me");
		(void) fakePaper;
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl ;
	}
    return (0);
}
