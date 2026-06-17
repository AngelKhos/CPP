#ifndef ITER_HPP
#define ITER_HPP

template<typename Array>
void iter(Array *array, const size_t size, void f(Array &i))
{
    for (size_t i = 0; i < size; i++)
        f(array[i]);
}

template<typename Array>
void iter(const Array *array, const size_t size, void f(const Array &i))
{
    for (size_t i = 0; i < size; i++)
        f(array[i]);
}

#endif