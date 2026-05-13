#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename Char>
void toupper(Char &c)
{
    if (islower(c))
        c -= 32;
}

template<typename Array>
void iter(Array *array, size_t size, void f(Array &i))
{
    for (size_t i = 0; i < size; i++)
        f(array[i]);
}

#endif