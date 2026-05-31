#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 20
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    std::cout << "Assigning random values..." << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {

        std::cout << "Numbers value: " << numbers[i] << ", mirror value: " << mirror[i] << std::endl;
        if (mirror[i] != numbers[i])
        {
            std::cout << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "Values are all equal." << std::endl;


    {
        std::cout << "Scope test..." << std::endl;
        Array<int> tmp;
        tmp = numbers;
        Array<int> test(tmp);
    }


    try
    {
        std::cout << "Calling operator[] with size '-2'..." << std::endl;
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << '\n';
    }
    try
    {
        std::cout << "Calling operator[] with size '" << MAX_VAL<< "'..." << std::endl;
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << '\n';
    }
    std::cout << "Assigning new random values..." << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << "index: " << i << ", number:" << numbers[i] << std::endl;
    }
    delete [] mirror;
    return 0;
}