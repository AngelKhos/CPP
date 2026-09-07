#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <cstdlib>
#include <iostream>

#define DEBUG 0

typedef std::vector<int> t_group;

typedef struct s_pair
{
    t_group s;
    t_group b;
} t_pair;

typedef std::deque<int> t_dgroup;

typedef struct s_dpair
{
    t_dgroup s;
    t_dgroup b;
} t_dpair;


std::ostream &operator<<(std::ostream &out, const t_pair &pair);
std::ostream &operator<<(std::ostream &out, const t_group &group);
std::ostream &operator<<(std::ostream &out, const t_dpair &pair);
std::ostream &operator<<(std::ostream &out, const t_dgroup &group);

#endif