/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: authomas <authomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:03:22 by authomas          #+#    #+#             */
/*   Updated: 2026/01/02 17:28:44 by authomas         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void replace(std::string &file, const std::string &s1, const std::string &s2)
{
    size_t index;
    index = file.find(s1);
    while (index != std::string::npos)
    {
        file.erase(index, s1.length());
        file.insert(index, s2);
        index = file.find(s1);
    }
    return ;
}

int main(int ac, char **av)
{
    if (ac != 4)
        return (1);
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::string filename = av[1];
    std::ifstream infile(filename.c_str());
    if (!infile.is_open())
        return (1);
    std::string file_line;
    std::string file_buff;
    while(std::getline(infile, file_line))
    {
        file_buff += file_line + "\n";
    }
    file_buff.erase(file_buff.length() - 1, 1);
    replace(file_buff, s1, s2);
    filename += ".replace";
    std::ofstream outfile(filename.c_str());
    if (!outfile.is_open())
        return (1);
    outfile << file_buff;
    return (0);
}