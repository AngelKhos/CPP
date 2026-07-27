#include "PmergeMe.hpp"

#include <vector>
#include <cstdlib>
#include <iostream>

int main(int ac, char **av)
{
     if (ac == 1)
        return 1;
    
    std::vector<int> list;

    for (int i = 1; i < ac; i++)
    {
        int number = atoi(av[i]);
        if (number < 0)
            return 1;
        list.push_back(number);
    }
    for (std::vector<int>::iterator it = list.begin(); it != list.end(); it++ )
        std::cout << *it << " ";
    std::cout << std::endl;
    return 0;
}