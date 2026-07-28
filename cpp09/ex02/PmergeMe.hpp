#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <cstdlib>
#include <iostream>

typedef std::vector<int> t_group;

typedef struct s_pair
{
    t_group s;
    t_group b;
} t_pair;

std::ostream &operator<<(std::ostream &out, const t_pair &pair);
std::ostream &operator<<(std::ostream &out, const t_group &group);
#endif