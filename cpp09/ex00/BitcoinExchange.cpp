#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream infile("data.csv");
    if (!infile)
        throw std::runtime_error("can't open file");

    std::string file_line;
    std::getline(infile, file_line);
    while(std::getline(infile, file_line))
    {
        int sep = file_line.find(',');

        std::string key = file_line.substr(0, sep);
        std::string value = file_line.substr(sep, file_line.size());

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
    return (data[input]);
}