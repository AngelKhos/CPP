/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 23:22:12 by authomas          #+#    #+#             */
/*   Updated: 2026/03/17 20:28:28 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// void bureaucratConstructionTest()
// {
//     std::cout << "--- bureaucrat construction tests---" << std::endl;
//     try{
//         Bureaucrat Best(0);
//         std::cout << "Bureaucrat has been created" << std::endl;
//     }
//     catch (std::exception &e)
//     {
//         std::cout << "The bureaucrat couldn't be created because " << e.what() << std::endl;
//     }
//     try{
//         Bureaucrat Worst(151);
//         std::cout << "Bureaucrat has been created" << std::endl;
//     }
//     catch (std::exception &e)
//     {
//         std::cout << "The bureaucrat couldn't be created because " << e.what() << std::endl;
//     }
//     std::cout << std::endl;
// }

// void bureaucratRankTests()
// {
//     Bureaucrat John("John", 1);
//     std::cout << "--- rank increment test ---" << std::endl << John << std::endl;
//     try {
//         John.promote();
//     }
//     catch (std::exception &e)
//     {
//         std::cout << "The bureaucrat couldn't be promoted because " << e.what() << std::endl;
//     }
//     std::cout << std::endl;


//     Bureaucrat Gohn("Gohn", 150);
//     std::cout << "--- rank decrement test ---" << std::endl << Gohn << std::endl;
//     try {
//         Gohn.demote();
//     }
//     catch (std::exception &e)
//     {
//         std::cout << "The bureaucrat couldn't be demoted because " << e.what() << std::endl;
//     }
//     std::cout << std::endl;
// }

// void formConstructionTest()
// {
//     std::cout << "--- Form construction test ---" << std::endl;
//     try {
//         Form a24(1, 0);// comment it during the evaluation
//         Form a25(0, 1);
//     }
//     catch (std::exception &e)
//     {
//         std::cout << "The form couldn't be created because " << e.what() << std::endl;
//     }
//     try {
//         Form a24(1, 151);// comment it during the evaluation
//         Form a25(151, 1);
//     }
//     catch (std::exception &e)
//     {
//         std::cout << "The form couldn't be created because " << e.what() << std::endl;
//     }
//     std::cout << std::endl;
// }

// void	basicTest()
// {
// 	std::cout << "___" << __func__ << "___" << std::endl;
// 	try
// 	{
// 		Form f("test", 100, 50);
// 		std::cout << f << std::endl;
// 		Bureaucrat b("albert", 90);
// 		std::cout << b << std::endl;
// 		b.signForm(f);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// }

// void	signExeption()
// {
// 	std::cout << "___" << __func__ << "___" << std::endl;
// 	try
// 	{
// 		Form f("test", 100, 50);
// 		std::cout << f << std::endl;
// 		Bureaucrat b("albert", 150);
// 		std::cout << b << std::endl;
// 		b.signForm(f);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// }

int main(void)
{
    // bureaucratConstructionTest();
    // bureaucratRankTests();
    // formConstructionTest();
    // basicTest();
    // signExeption();
    
    return (0);
}
