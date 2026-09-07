#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &src)
{
    *this = src;
}
RPN &RPN::operator=(const RPN &src)
{
    data = src.data;
    return (*this);
}

void RPN::put_in_stack(const float elem)
{
    data.push(elem);
}

float RPN::get_from_stack()
{
    float elem = data.top();
    data.pop();
    return (elem);
}

size_t RPN::getsize()
{
    return (data.size());
}

RPN::~RPN(){}