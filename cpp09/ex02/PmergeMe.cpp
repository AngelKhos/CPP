#include "PmergeMe.hpp"

std::ostream &operator<<(std::ostream &out, const t_pair &pair)
{
    out << "(";
    if (pair.b.empty())
        out << pair.s;
    else
        out << pair.s << " " << pair.b;
    out << ")";
    return (out);
}

std::ostream &operator<<(std::ostream &out, const t_group &group)
{
    out << "'" << group[0];
    for (size_t i = 1; i < group.size() ; i++)
        out << " " << group[i];
    out << "'";
    return (out);
}