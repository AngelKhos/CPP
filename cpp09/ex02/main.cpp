#include "PmergeMe.hpp"

std::vector<t_pair> group_to_pair(std::vector<t_group> groups)
{
    std::vector<t_pair> pairs;

    for (size_t i = 0; i < groups.size(); i++)
    {
        for(size_t j = 0; j < groups[i].size()/2; j++)
            pairs[i].s.push_back(groups[i][j]);
        for(size_t j = groups[i].size()/2; j < groups[i].size(); j++)
            pairs[i].b.push_back(groups[i][j]);
    }
    return (pairs);
}

int jacobsthal(int index)
{
    if (index == 0)
        return (1);
    if (index == 1)
        return (3);
    int a = 1;
    int b = 3;
    for (int i = 1; i < index; i++)
    {
        int tmp = b;
        b = b + 2*a;
        a = tmp;
    }
    return (b);
}

t_pair merge_pair(const t_pair first, const t_pair second)
{
    t_pair merged;

    if (first.b.back() < second.b.back())
    {
        for (size_t i = 0; i < first.s.size(); i++)
            merged.s.push_back(first.s[i]);
        for (size_t i = 0; i < first.b.size(); i++)
            merged.s.push_back(first.b[i]);
        for (size_t i = 0; i < second.s.size(); i++)
            merged.b.push_back(second.s[i]);
        for (size_t i = 0; i < second.b.size(); i++)
            merged.b.push_back(second.b[i]);
    }
    else
    {
        for (size_t i = 0; i < first.s.size(); i++)
            merged.b.push_back(first.s[i]);
        for (size_t i = 0; i < first.b.size(); i++)
            merged.b.push_back(first.b[i]);
        for (size_t i = 0; i < second.s.size(); i++)
            merged.s.push_back(second.s[i]);
        for (size_t i = 0; i < second.b.size(); i++)
            merged.s.push_back(second.b[i]);
    }
    return (merged);
}

std::vector<t_group> recursive_sort(std::vector<t_pair>& pairs)
{
    std::vector<t_pair> merged_pairs;
    std::vector<t_group> excluded;

    if (pairs.back().b.empty())
    {
        excluded.push_back(pairs.back().s);
        pairs.pop_back();
    }
    size_t i = 0;
    while(i < pairs.size())
    {
        t_pair cur;
        if(i + 1 < pairs.size())
        {
            cur = merge_pair(pairs[i], pairs[i + 1]);
            merged_pairs.push_back(cur);
        }
        else
        {
            excluded.push_back(pairs[i].s);
            excluded.push_back(pairs[i].b);
        }
        i = i + 2;
    }
    for (std::vector<t_pair>::iterator it = merged_pairs.begin(); it != merged_pairs.end(); it++)
        std::cout << *it;
    for (std::vector<t_group>::iterator it = excluded.begin(); it != excluded.end(); it++)
        std::cout << *it;
    std::cout << std::endl;
    if (merged_pairs.size() > 1)
        merged_pairs = group_to_pair(recursive_sort(merged_pairs));
    
    
}

void sort(std::vector<int> list)
{
    std::vector<t_pair> pairs;
    int excluded;
    size_t i = 0;
    while(i < list.size())
    {
        t_pair cur;
        if(i + 1 < list.size())
        {
            if(list[i] < list[i + 1])
            {
                cur.s.push_back(list[i]);
                cur.b.push_back(list[i + 1]);
            }
            else
            {
                cur.s.push_back(list[i + 1]);
                cur.b.push_back(list[i]);
            }
            pairs.push_back(cur);
        }
        else
            excluded = list[i];
        
        i = i + 2;
    }
    for (std::vector<t_pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
        std::cout << *it;
    std::cout << " '" << excluded << "'" << std::endl;

    // std::cout << "test" << std::endl;
    // std::cout << merge_pair(pairs[0], pairs[1]) << merge_pair(pairs[2], pairs[3])<< std::endl;
    // std::cout << merge_pair(merge_pair(pairs[0], pairs[1]), merge_pair(pairs[2], pairs[3])) << std::endl;
    recursive_sort(pairs);
}

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
    std::cout << "Unsorted list: ";
    for (std::vector<int>::iterator it = list.begin(); it != list.end(); it++ )
        std::cout << *it << " ";
    std::cout << std::endl;

    sort(list);
    return 0;
}