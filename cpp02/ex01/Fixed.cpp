/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angel <angel@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:09:18 by authomas          #+#    #+#             */
/*   Updated: 2026/01/06 18:58:31 by angel            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int Fixed::size = 8;

Fixed::Fixed()
{
    std::cout << "Default contructor called" << std::endl;
    value = 0;
}

Fixed::Fixed(const Fixed &_fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    value = _fixed.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &_fixed)
{
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &_fixed)
    {
        value = _fixed.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(value);
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}