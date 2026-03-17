/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:55:04 by authomas          #+#    #+#             */
/*   Updated: 2026/03/16 16:48:38 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
#define SHRUBERRYCREATIONFORM_HPP

#include "AForm.hpp"

class ShruberryCreationForm : public AForm
{
    public:
        ShruberryCreationForm();
        ShruberryCreationForm(std::string _target);
        ShruberryCreationForm(const ShruberryCreationForm &_Form);
        ~ShruberryCreationForm();

        ShruberryCreationForm &operator=(const ShruberryCreationForm &obj);

        void execute(Bureaucrat const &executor) const;

        
    private:
        std::string target;
};

#endif