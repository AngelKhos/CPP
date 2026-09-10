#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error" << std::endl;
        return (1);
    }

    std::string input(av[1]);

    if (input.empty())
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    RPN data;

    for (size_t i = 0; i < input.size(); i++)
    {
        if (isblank(input[i]))
                continue ;
        if (isdigit(input[i]))
            data.put_in_stack(input[i] - '0');
        else if (std::string("+-/*").find(input[i]) != std::string::npos)
        {
            if (data.getsize() < 2)
            {
                std::cout << "Error" << std::endl;
                return (1);
            }
            float b = data.get_from_stack();
            float a = data.get_from_stack();
            switch (input[i])
            {
                case '+':
                    data.put_in_stack(a + b);
                    break;
                case '-':
                    data.put_in_stack(a - b);
                    break;
                case '/':
                    data.put_in_stack(a / b);
                    break;
                case '*':
                    data.put_in_stack(a * b);
                    break;
            }
        }
        else
        {
            std::cout << "Error" << std::endl;
            return (1);
        }
    }
    if (data.getsize() != 1)
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    std::cout << data.get_from_stack() << std::endl;
    return (0);
}