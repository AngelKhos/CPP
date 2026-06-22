#include "Span.hpp"

Span::Span() : array(0), size(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Span::Span(unsigned int n) : array(n) , size(n)
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
}

Span::~Span(){}

void Span::addNumber(int number)
{
    if(array.size() != size)
        array.push_back(number);
    else
        throw std::out_of_range("Span is already full");

    std::sort(array.front(), array.back());
}
int Span::shortestSpan()
{

}
int Span::longestSpan()
{

}