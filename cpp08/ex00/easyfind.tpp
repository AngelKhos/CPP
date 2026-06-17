#include "easyfind.hpp"

const char* NotFoundException::what() const throw()
{
    return ("Not found");
}

template<typename T>
int easyfind(T const &c, int to_find)
{
    typename T::const_iterator it = std::find(c.begin(), c.end(), to_find);
    if(it != c.end())
        return (*it);
    throw NotFoundException();
}
