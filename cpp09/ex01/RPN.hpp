#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>

class RPN
{
    public:
        RPN();
        RPN(const RPN &);
        RPN &operator=(const RPN &);
        ~RPN();
        
        void put_in_stack(const float);
        float get_from_stack();
        size_t getsize();

    private:
        std::stack<float> data;
};

#endif