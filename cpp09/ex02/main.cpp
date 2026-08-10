#include "PmergeMe.hpp"
#include <cmath>
#include <algorithm>

std::vector<t_pair> group_to_pair(std::vector<t_group> groups)
{
    std::vector<t_pair> pairs;

    for (size_t i = 0; i < groups.size(); i++)
    {
        t_pair cur;
        for(size_t j = 0; j < groups[i].size() / 2; j++)
            cur.s.push_back(groups[i][j]);
        for(size_t j = groups[i].size() / 2; j < groups[i].size(); j++)
            cur.b.push_back(groups[i][j]);
        pairs.push_back(cur);
    }
    return (pairs);
}

int jacobsthal(int index)
{
    int a = 1;
    int b = 3;
    if (index == 0)
        return (a);
    if (index == 1)
        return (b);
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

// void insert(t_group to_insert, std::vector<t_group> &main, size_t range)
// {
//     size_t index = range / 2;
//     std::cout << "main range : ";
//         for (size_t i = 0; i < range; i++)
//             std::cout << main[i] << " ";
//         std::cout << std::endl;
//     while (range / 2 != 1)
//     {

//         std::cout << "main range : ";
//         for (size_t i = 0; i < range; i++)
//             std::cout << main[i] << " ";
//         std::cout << std::endl;

//         if (main[index].back() < to_insert.back())
//             index += range / 2;
//         else
//             index -= range / 2;
//         range = range / 2;
//     }
//     if (index == main.size())
//         main.push_back(to_insert);
//     else if (main[index].back() < to_insert.back())
//         main.insert(main.begin() + index + 1, to_insert);
//     else
//         main.insert(main.begin() + index, to_insert);

// }
// tkt ca marche mtn

void prep_insert(std::vector<t_group> &main, std::vector<t_group> &to_insert, std::vector<t_group> excluded, std::vector<t_pair> pairs)
{
    for (std::vector<t_pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        if (it == pairs.begin())
        {
            main.push_back(it->s);
            main.push_back(it->b);

        }
        else
        {
            main.push_back(it->b);
            to_insert.push_back(it->s);
        }
    }
    if (!excluded.empty())
    {
        t_group group;
        for (size_t i = 0; i < excluded[0].size(); i++)
            group.push_back(excluded[0][i]);
        for (size_t i = 0; i < excluded[1].size(); i++)
            group.push_back(excluded[1][i]);
        if(std::find(to_insert.begin(), to_insert.end(), group) == to_insert.end())
            to_insert.push_back(group);
    }
}

void insert(t_group to_insert, std::vector<t_group> &main, size_t range)
{
    size_t left = 0;
    size_t right = range - 1;

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (to_insert.back() > main[mid].back())
            left = mid + 1;
        else
            right = mid;
    }
    main.insert(main.begin() + left, to_insert);
}

void jacobsthal_insert(std::vector<t_group> &main, std::vector<t_group> &to_insert)
{
    int jx = 1, last_j = 1;
    while(!to_insert.empty())
    {
        int jacob = jacobsthal(jx);
        size_t search_index = std::pow(2, jx + 1) - 1;
        size_t elements_to_insert = jacob - last_j;

        if (search_index <= main.size() && elements_to_insert <= to_insert.size())
        {
            for (size_t i = 1; i <= elements_to_insert; i++)
            {
                insert(to_insert[elements_to_insert - i], main, search_index);
                to_insert.erase(to_insert.begin() + elements_to_insert - i);
            }
            last_j = jacob;
            jx++;

        }
        else
        {
            insert(to_insert[to_insert.size() - 1], main, main.size() - 1);
            to_insert.erase(to_insert.begin() + to_insert.size() - 1);
        }
    }
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

    if (merged_pairs.size() > 1)
        merged_pairs = group_to_pair(recursive_sort(merged_pairs));
    
    if (merged_pairs.empty())
        merged_pairs = pairs;
    std::vector<t_group> to_insert;
    std::vector<t_group> main;

    prep_insert(main, to_insert, excluded, merged_pairs);
    jacobsthal_insert(main, to_insert);

    for (std::vector<t_group>::iterator it = main.begin(); it != main.end(); it++)
        std::cout << *it;
    std::cout << std::endl;

    return (main);
}

void sort(std::vector<int> list)
{
    std::vector<t_pair> pairs;
    std::vector<t_group> excluded;
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
        {
            t_group tmp;
            t_group tmp2;
            tmp.push_back(list[i]);
            excluded.push_back(tmp);
            excluded.push_back(tmp2);
        }
        i = i + 2;
    }

    std::vector<t_group> sorted = recursive_sort(pairs);
    std::vector<t_group> main;
    std::vector<t_group> to_insert;

    pairs = group_to_pair(sorted);

    for (std::vector<t_pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
        std::cout << *it;
    std::cout << std::endl;

    prep_insert(main, to_insert, excluded, pairs);
    for (std::vector<t_group>::iterator it = main.begin(); it != main.end(); it++)
        std::cout << *it;
    std::cout << std::endl;
    jacobsthal_insert(main, to_insert);

    for (std::vector<t_group>::iterator it = main.begin(); it != main.end(); it++)
        std::cout << *it;
    std::cout << std::endl;
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