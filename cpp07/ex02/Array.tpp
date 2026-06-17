#include "Array.hpp"

template<typename T>
Array<T>::Array()
{
    std::cout << "Default constructor called" << std::endl;
    array = new T[0];
    size = 0;
}

template<typename T>
Array<T>::Array(unsigned int _size)
{
    std::cout << "Size constructor called" << std::endl;
    array = new T[_size];
    size = _size;
}

template<typename T>
Array<T>::Array(const Array &a)
{
    std::cout << "Copy constructor called" << std::endl;
    array = new T[a.getSize()];
    size = a.getSize();

    for (size_t i = 0; i < size; i++)
    {
        array[i] = a[i];
    }
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &a)
{
    std::cout << "Operator '=' called" << std::endl;
    delete[] array;
    array = new T[a.getSize()];
    size = a.getSize();

    for (size_t i = 0; i < size; i++)
    {
        array[i] = a[i];
    }
    return (*this);
}

template<typename T>
Array<T>::~Array()
{
    std::cout << "Destructor called" << std::endl;
    delete[] array;
}

template<typename T>
T& Array<T>::operator[](size_t idx)
{
    if (idx >= size)
        throw OutOfBoundException();
    return array[idx];
}

template<typename T>
const T& Array<T>::operator[](size_t idx) const
{
    if (idx >= size)
        throw OutOfBoundException();
    return array[idx];
}

template<typename T>
const char* Array<T>::OutOfBoundException::what() const throw()
{
    return ("size is out of bounds");
}

template<typename T>
size_t Array<T>::getSize() const
{
    return (size);
}