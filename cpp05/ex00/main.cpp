/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 23:22:12 by authomas          #+#    #+#             */
/*   Updated: 2026/03/10 00:04:23 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "---construction tests---" << std::endl;
    try{
        Bureaucrat Best(0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try{
        Bureaucrat Worst(151);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    Bureaucrat John("John", 1);
    std::cout << "--- rank increment test ---" << std::endl << John << std::endl;
    try {
        John.promote();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    Bureaucrat Gohn("Gohn", 150);
    std::cout << "--- rank decrement test ---" << std::endl << Gohn << std::endl;
    try {
        Gohn.demote();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
