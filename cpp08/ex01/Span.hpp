#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span
{
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &cpy);
        Span &operator=(const Span &cpy);
        ~Span();

        void addNumber(int number);
        int shortestSpan();
        int longestSpan();

    private:
        std::vector<int> array;
        size_t size;
};

#endif