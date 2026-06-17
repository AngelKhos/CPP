#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>

class NotFoundException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

#include "easyfind.tpp"

#endif