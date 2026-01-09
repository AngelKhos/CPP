/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:09:18 by authomas          #+#    #+#             */
/*   Updated: 2026/01/09 18:56:55 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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

Fixed::Fixed(const int _value)
{
    std::cout << "Int contructor called" << std::endl;
    value = _value << size;
}

Fixed::Fixed(const float _value)
{
    std::cout << "Float contructor called" << std::endl;
    value = _value * (1 << size);
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

float Fixed::toFloat() const
{
    return ((float)(value / (1 << size)));
}

int Fixed::toInt() const
{
    return ((int)(value >> size));
}

std::ostream &operator<<(std::ostream &out, const Fixed &_fixed)
{
    out << _fixed.toFloat();
    return (out);
}