#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
    public:
        Array();
        Array(unsigned int _size);
        Array(const Array &a);
        Array &operator=(const Array &a);
        ~Array();

        T& operator[](size_t idx);
        const T& operator[](size_t idx) const;

        class OutOfBoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
        size_t getSize() const;

    private:
        T *array;
        size_t size;
};

#include "Array.tpp"

#endif