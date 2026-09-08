#include "PmergeMe.hpp"
#include <cmath>
#include <ctime>
#include <iomanip>

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

std::vector<t_dpair> group_to_pair(std::vector<t_dgroup> groups)
{
    std::vector<t_dpair> pairs;

    for (size_t i = 0; i < groups.size(); i++)
    {
        t_dpair cur;
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
t_dpair merge_pair(const t_dpair first, const t_dpair second)
{
    t_dpair merged;

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
        to_insert.push_back(group);
    }
}
void prep_insert(std::vector<t_dgroup> &main, std::vector<t_dgroup> &to_insert, std::vector<t_dgroup> excluded, std::vector<t_dpair> pairs)
{
    for (std::vector<t_dpair>::iterator it = pairs.begin(); it != pairs.end(); it++)
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
        t_dgroup group;
        for (size_t i = 0; i < excluded[0].size(); i++)
            group.push_back(excluded[0][i]);
        for (size_t i = 0; i < excluded[1].size(); i++)
            group.push_back(excluded[1][i]);
        to_insert.push_back(group);
    }
}

void insert(t_group to_insert, std::vector<t_group> &main, size_t range)
{
    size_t left = 0;
    size_t right = range;
    size_t mid = left + (right - left) / 2;

    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (to_insert.back() > main[mid].back())
            left = mid + 1;
        else
            right = mid;
    }
    if (to_insert.back() > main[mid].back())
        main.insert(main.begin() + mid + 1, to_insert);
    else
        main.insert(main.begin() + mid, to_insert);
}
void insert(t_dgroup to_insert, std::vector<t_dgroup> &main, size_t range)
{
    size_t left = 0;
    size_t right = range;
    size_t mid = left + (right - left) / 2;

    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (to_insert.back() > main[mid].back())
            left = mid + 1;
        else
            right = mid;
    }
    if (to_insert.back() > main[mid].back())
        main.insert(main.begin() + mid + 1, to_insert);
    else
        main.insert(main.begin() + mid, to_insert);
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
            insert(to_insert[to_insert.size() - 1], main, main.size());
            to_insert.erase(to_insert.begin() + to_insert.size() - 1);
        }
    }
}
void jacobsthal_insert(std::vector<t_dgroup> &main, std::vector<t_dgroup> &to_insert)
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
            insert(to_insert[to_insert.size() - 1], main, main.size());
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
    if (DEBUG)
    {
        for (std::vector<t_pair>::iterator it = merged_pairs.begin(); it != merged_pairs.end(); it++)
            std::cout << *it;
        std::cout << std::endl;
    }

    if (merged_pairs.size() > 1)
        merged_pairs = group_to_pair(recursive_sort(merged_pairs));
    
    if (merged_pairs.empty())
        merged_pairs = pairs;

    std::vector<t_group> to_insert;
    std::vector<t_group> main;

    prep_insert(main, to_insert, excluded, merged_pairs);

    if (DEBUG)
    {
        std::cout << "main: ";
        for (std::vector<t_group>::iterator it = main.begin(); it != main.end(); it++)
            std::cout << *it;
        std::cout << std::endl;
        std::cout << "pend: ";
        for (std::vector<t_group>::iterator it = to_insert.begin(); it != to_insert.end(); it++)
            std::cout << *it;
        std::cout << std::endl;
    }

    jacobsthal_insert(main, to_insert);

    if (DEBUG)
    {
        std::cout << "after insertion: ";
        for (std::vector<t_group>::iterator it = main.begin(); it != main.end(); it++)
            std::cout << *it;
        std::cout << std::endl;
    }

    return (main);
}
std::vector<t_dgroup> recursive_sort(std::vector<t_dpair>& pairs)
{
    std::vector<t_dpair> merged_pairs;
    std::vector<t_dgroup> excluded;

    if (pairs.back().b.empty())
    {
        excluded.push_back(pairs.back().s);
        pairs.pop_back();
    }
    size_t i = 0;
    while(i < pairs.size())
    {
        t_dpair cur;
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

    if (DEBUG)
    {
        for (std::vector<t_dpair>::iterator it = merged_pairs.begin(); it != merged_pairs.end(); it++)
            std::cout << *it;
        std::cout << std::endl;
    }

    if (merged_pairs.size() > 1)
        merged_pairs = group_to_pair(recursive_sort(merged_pairs));
    
    if (merged_pairs.empty())
        merged_pairs = pairs;

    std::vector<t_dgroup> to_insert;
    std::vector<t_dgroup> main;

    prep_insert(main, to_insert, excluded, merged_pairs);

    if (DEBUG)
    {
        std::cout << "main: ";
        for (std::vector<t_dgroup>::iterator it = main.begin(); it != main.end(); it++)
            std::cout << *it;
        std::cout << std::endl;
        std::cout << "pend: ";
        for (std::vector<t_dgroup>::iterator it = to_insert.begin(); it != to_insert.end(); it++)
            std::cout << *it;
        std::cout << std::endl;
    }

    jacobsthal_insert(main, to_insert);

    if (DEBUG)
    {
        std::cout << "after insertion: ";
        for (std::vector<t_dgroup>::iterator it = main.begin(); it != main.end(); it++)
            std::cout << *it;
        std::cout << std::endl;
    }

    return (main);
}

int is_sorted(std::vector<t_group> list)
{
    for (std::vector<t_group>::iterator it = list.begin(); it != list.end(); it++)
    {
        if ((it + 1) != list.end() && it[0][0] > (it + 1)[0][0])
            return (0);
    }
    return (1);
}

int is_sorted(std::vector<t_dgroup> list)
{
    for (std::vector<t_dgroup>::iterator it = list.begin(); it != list.end(); it++)
    {
        if ((it + 1) != list.end() && it[0][0] > (it + 1)[0][0])
            return (0);
    }
    return (1);
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

    if (DEBUG)
    {
        std::cout << "before recursive: "; 
        for (std::vector<t_pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
            std::cout << *it;
        std::cout << std::endl;
    }

    if (list.size() == 1)
    {
        std::cout << "'" << list[0] << "'" << std::endl;
        return ;
    }
    if (list.size() > 3)
    {
        std::vector<t_group> sorted = recursive_sort(pairs);
        pairs = group_to_pair(sorted);
    }

    if (DEBUG)
    {
        std::cout << "after recursive: "; 
        for (std::vector<t_pair>::iterator it = pairs.begin(); it != pairs.end(); it++)
            std::cout << *it;
        std::cout << std::endl;
    }

    std::vector<t_group> main;
    std::vector<t_group> to_insert;

    prep_insert(main, to_insert, excluded, pairs);

    if (DEBUG)
    {
        std::cout << "main: ";
        for (std::vector<t_group>::iterator it = main.begin(); it != main.end(); it++)
            std::cout << *it;
        std::cout << std::endl;
        std::cout << "pend: ";
        for (std::vector<t_group>::iterator it = to_insert.begin(); it != to_insert.end(); it++)
            std::cout << *it;
        std::cout << std::endl;
    }

    jacobsthal_insert(main, to_insert);

    std::cout << "After: ";
    for (std::vector<t_group>::iterator it = main.begin(); it != main.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    if (DEBUG)
    {
        if(is_sorted(main))
            std::cout << "successfully sorted" << std::endl;
        else
            std::cout << "not sorted" << std::endl;
    }
}
void sort(std::deque<int> list)
{
    std::vector<t_dpair> pairs;
    std::vector<t_dgroup> excluded;
    size_t i = 0;
    while(i < list.size())
    {
        t_dpair cur;
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
            t_dgroup tmp;
            t_dgroup tmp2;
            tmp.push_back(list[i]);
            excluded.push_back(tmp);
            excluded.push_back(tmp2);
        }
        i = i + 2;
    }

    if (DEBUG)
    {
        std::cout << "before recursive: "; 
        for (std::vector<t_dpair>::iterator it = pairs.begin(); it != pairs.end(); it++)
            std::cout << *it;
        std::cout << std::endl;
    }

    if (list.size() == 1)
    {
        std::cout << "'" << list[0] << "'" << std::endl;
        return ;
    }
    if (list.size() > 3)
    {
        std::vector<t_dgroup> sorted = recursive_sort(pairs);
        pairs = group_to_pair(sorted);
    }

    if (DEBUG)
    {
        std::cout << "after recursive: "; 
        for (std::vector<t_dpair>::iterator it = pairs.begin(); it != pairs.end(); it++)
            std::cout << *it;
        std::cout << std::endl;
    }

    std::vector<t_dgroup> main;
    std::vector<t_dgroup> to_insert;

    prep_insert(main, to_insert, excluded, pairs);

    if (DEBUG)
    {
        std::cout << "main: ";
        for (std::vector<t_dgroup>::iterator it = main.begin(); it != main.end(); it++)
            std::cout << *it;
        std::cout << std::endl;
        std::cout << "pend: ";
        for (std::vector<t_dgroup>::iterator it = to_insert.begin(); it != to_insert.end(); it++)
            std::cout << *it;
        std::cout << std::endl;
    }

    jacobsthal_insert(main, to_insert);

    if (DEBUG)
    {
        std::cout << "sorted list: ";
        for (std::vector<t_dgroup>::iterator it = main.begin(); it != main.end(); it++)
            std::cout << *it;
        std::cout << std::endl;
        if(is_sorted(main))
            std::cout << "successfully sorted" << std::endl;
        else
            std::cout << "not sorted" << std::endl;
    }
}

int main(int ac, char **av)
{
     if (ac == 1)
        return 1;

   

    std::cout << "Before: ";
    for (int i = 1; i < ac; i++)
        std::cout << av[i] << " ";
    std::cout << std::endl;

    std::clock_t start = clock();
    std::vector<int> list;
    for (int i = 1; i < ac; i++)
    {
        int number = atoi(av[i]);
        if (number < 0)
            return 1;
        list.push_back(number);
    }
    sort(list);
    std::clock_t end = clock();

    std::clock_t dstart = clock();
    std::deque<int> dlist;
    for (int i = 1; i < ac; i++)
    {
        int number = atoi(av[i]);
        if (number < 0)
            return 1;
        dlist.push_back(number);
    }
    sort(dlist);
    std::clock_t dend = clock();

    std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector: " << std::fixed << std::setprecision(6) << static_cast<double>(end - start) / CLOCKS_PER_SEC << " us" << std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque: " << std::fixed << std::setprecision(6) << static_cast<double>(dend - dstart) / CLOCKS_PER_SEC << " us" << std::endl;

    return 0;
}