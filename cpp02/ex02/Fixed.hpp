/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:09:21 by authomas          #+#    #+#             */
/*   Updated: 2026/01/10 17:01:01 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>


class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed &_Fixed);
        Fixed(const int _value);
        Fixed(const float _value);
        Fixed &operator=(const Fixed &_Fixed);
        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);
        bool operator<(const Fixed &_Fixed) const;
        bool operator>(const Fixed &_Fixed) const;
        bool operator<=(const Fixed &_Fixed) const;
        bool operator>=(const Fixed &_Fixed) const;
        bool operator==(const Fixed &_Fixed) const;
        bool operator!=(const Fixed &_Fixed) const;
        Fixed operator+(const Fixed &_Fixed) const;
        Fixed operator-(const Fixed &_Fixed) const;
        Fixed operator*(const Fixed &_Fixed) const;
        Fixed operator/(const Fixed &_Fixed) const;
        ~Fixed();

        int getRawBits() const;
        void setRawBits(int const raw);
        float toFloat() const;
        int toInt() const;
        static Fixed &min(Fixed &f1, Fixed &f2);
        static const Fixed &min(const Fixed &f1, const Fixed &f2);
        static Fixed &max(Fixed &f1, Fixed &f2);
        static const Fixed &max(const Fixed &f1, const Fixed &f2);

    private:
        int value;
        static const int size;
};

std::ostream &operator<<(std::ostream &out, const Fixed &_Fixed);

#endif