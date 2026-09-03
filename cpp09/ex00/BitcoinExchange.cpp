#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream infile("data.csv");
    if (!infile)
        throw std::runtime_error("Error: could not open file");

    std::string file_line;
    std::getline(infile, file_line);
    while(std::getline(infile, file_line))
    {
        int sep = file_line.find(',');

        std::string key = file_line.substr(0, sep);
        std::string value = file_line.substr(sep + 1, file_line.size());

        data[key] = value;
    }
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    *this = src;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    data = src.data;
    return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

std::string BitcoinExchange::getfrom(std::string input)
{
    std::string value = data[input];

    if (value == "")
    {
        std::map<std::string, std::string>::iterator it = data.lower_bound(input);
        if (it == data.begin())
            throw (std::runtime_error("Error: date out of range"));
        if (it == data.end())
            throw (std::runtime_error("Error: value not found in database"));
        it--;
        value = (*it).second;
    }
    
    return (value); 
}