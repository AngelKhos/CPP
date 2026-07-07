#include "Span.hpp"

Span::Span() : array(), size(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Span::Span(unsigned int n) : array() , size(n)
{
    std::cout << "Size constructor called" << std::endl;
}
Span::Span(const Span &cpy) : array(cpy.array), size(cpy.size)
{
    std::cout << "Copy constructor called" << std::endl;
}
Span &Span::operator=(const Span &cpy)
{
    array = cpy.array;
    size = cpy.size;
    return (*this);
}

Span::~Span(){}

void Span::addNumber(int number)
{
    if(array.size() <= size)
        array.push_back(number);
    else
        throw std::out_of_range("Span is already full");

    std::sort(array.begin(), array.end());
}

void Span::addNumber(int *numbers, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if(array.size() <= size)
            array.push_back(numbers[i]);
        else
            throw std::out_of_range("Span is already full");
    }
    std::sort(array.begin(), array.end());
}
int Span::shortestSpan()
{
    int span = longestSpan();
    int diff;
    for (std::vector<int>::iterator it = array.begin(); it != array.end(); it++)
    {
        std::vector<int>::iterator curr = it;
        it++;
        for (std::vector<int>::iterator it2 = it; it2 != array.end(); it2++)
        {
            diff = (*it2) - (*curr);
            if (diff < span)
                span = diff;
        }
        it--;
    }
    return (span);
}
int Span::longestSpan()
{
    std::vector<int>::iterator min = std::min_element(array.begin(), array.end());
    std::vector<int>::iterator max = std::max_element(array.begin(), array.end());

    return ((*max)-(*min));
}