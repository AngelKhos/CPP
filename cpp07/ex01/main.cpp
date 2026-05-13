#include <iostream>
#include "iter.hpp"

int main( void ) {
    char test[] = "coucou les copains";

    std::cout << "test :" << test << std::endl;

    ::iter(test, sizeof(test), toupper);

    std::cout << "test after iter :" << test << std::endl;
}