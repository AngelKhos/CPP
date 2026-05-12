/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalarconverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 01:45:57 by authomas          #+#    #+#             */
/*   Updated: 2026/03/18 01:50:59 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
    public:
        static void convert(std::string input);

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &_converter);
        ScalarConverter &operator=(const ScalarConverter &_converter);
        ~ScalarConverter();
};

#endif