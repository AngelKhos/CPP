/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:09:21 by authomas          #+#    #+#             */
/*   Updated: 2026/01/09 18:57:03 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed &_fixed);
        Fixed(const int _value);
        Fixed(const float _value);
        Fixed &operator=(const Fixed &_fixed);
        ~Fixed();

        int getRawBits() const;
        void setRawBits(int const raw);
        float toFloat() const;
        int toInt() const;

    private:
        int value;
        static const int size;
};

std::ostream &operator<<(std::ostream &out, const Fixed &_fixed);

#endif