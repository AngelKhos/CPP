/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:09:18 by authomas          #+#    #+#             */
/*   Updated: 2026/01/10 17:17:03 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::size = 8;

///////////////////CONSTRUCTORS////////////////////////

Fixed::Fixed(){ value = 0;}
Fixed::Fixed(const Fixed &_Fixed){ value = _Fixed.getRawBits();}
Fixed::Fixed(const int _value){ value = _value << size;}
Fixed::Fixed(const float _value){ value = _value * (float)(1 << size);}

//////////////////OPERATOR OVERLOADS////////////////////////

Fixed &Fixed::operator=(const Fixed &_Fixed)
{
    if (this != &_Fixed)
    {
        value = _Fixed.getRawBits();
    }
    return (*this);
}

Fixed &Fixed::operator++()
{
    this->value++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed old = *this;
    operator++();
    return (old);
}

Fixed &Fixed::operator--()
{
    this->value--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed old = *this;
    operator--();
    return (old);
}

bool Fixed::operator<(const Fixed &_Fixed) const
{
    return (value < _Fixed.value);
}

bool Fixed::operator>(const Fixed &_Fixed) const
{
    return (value > _Fixed.value);
}

bool Fixed::operator<=(const Fixed &_Fixed) const
{
    return (value <= _Fixed.value);
}

bool Fixed::operator>=(const Fixed &_Fixed) const
{
    return (value >= _Fixed.value);
}

bool Fixed::operator==(const Fixed &_Fixed) const
{
    return (value == _Fixed.value);
}

bool Fixed::operator!=(const Fixed &_Fixed) const
{
    return (value != _Fixed.value);
}

Fixed Fixed::operator+(const Fixed &_Fixed) const
{
    Fixed a;
    
    a.value = value + _Fixed.value;
    return (a);
}
        
Fixed Fixed::operator-(const Fixed &_Fixed) const
{
   Fixed a;
    
    a.value = value - _Fixed.value;
    return (a);
}

Fixed Fixed::operator*(const Fixed &_Fixed) const
{
    Fixed a;
    
    a = (this->toFloat() * _Fixed.toFloat());
    return (a);
}
        
Fixed Fixed::operator/(const Fixed &_Fixed) const
{
    return (value / (float)_Fixed.value);
}


///////////////////DESTRUCTOR/////////////////////

Fixed::~Fixed(){}

/////////////////////MEMBER FUNCTIONS////////////////////////

int Fixed::getRawBits() const { return(value);}

void Fixed::setRawBits(int const raw){ value = raw;}

float Fixed::toFloat() const { return (value / (float)(1 << size));}

int Fixed::toInt() const { return ((int)(value >> size));}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
    if (f1 < f2)
        return (f1);
    return (f2);
}
const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
     if (f1 < f2)
        return (f1);
    return (f2);
}
Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
      if (f1 > f2)
        return (f1);
    return (f2);
}
const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
    if (f1 > f2)
        return (f1);
    return (f2);
}

///////////////////OUTSIDE CLASS///////////////////////////

std::ostream &operator<<(std::ostream &out, const Fixed &_Fixed)
{
    out << _Fixed.toFloat();
    return (out);
}