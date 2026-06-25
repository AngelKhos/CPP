#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack
{
    public:
        MutantStack();
        MutantStack(const MutantStack<T> &);
        MutantStack<T> &operator=(const MutantStack<T> &);
        ~MutantStack();

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin();
        iterator end();
};

#endif