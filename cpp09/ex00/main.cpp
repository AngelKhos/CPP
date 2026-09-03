#include "BitcoinExchange.hpp"

int check_format(std::string input_str)
{
    int first = input_str.find_first_of(' ');
    int last = input_str.find_last_of(' ');

    if (input_str[first + 1] == input_str[last - 1] && input_str[first + 1] == '|')
        return (1);
    std::cout << "Error: bad input => " << input_str << std::endl;
    return (0);
}

int check_value(std::string value)
{
    double _value = atof(value.c_str());
    if (_value < 0)
    {
        std::cout << "Error: not a positive number" << std::endl;
        return (0);
    }
    if (value.find_first_not_of("1234567890.") != std::string::npos)
    {
        std::cout << "Error: invalid value" << std::endl;
        return (0);
    }
    if (_value > 1000)
    {
        std::cout << "Error: too large of a number" << std::endl;
        return (0);
    }
    return (1);
}

bool leap_calc(std::string year)
{
    int value = atoi(year.c_str());

    if ((value % 4 == 0 && value % 100 != 0) || (value % 400 == 0))
        return (true);
    return (false);
}

std::map<int, int> calendar_init(bool is_leap)
{
    std::map<int, int> calendar;

    calendar[1] = 31;
    if (is_leap)
        calendar[2] = 29;
    else
        calendar[2] = 28;
    calendar[3] = 31;
    calendar[4] = 30;
    calendar[5] = 31;
    calendar[6] = 30;
    calendar[7] = 31;
    calendar[8] = 31;
    calendar[9] = 30;
    calendar[10] = 31;
    calendar[11] = 30;
    calendar[12] = 31;

    return (calendar);
}

int check_key(std::string key)
{
    if (key.find_first_not_of("1234567890-") != std::string::npos)
        return (0);

    size_t sep1 = key.find_first_of('-');
    size_t sep2 = key.find_last_of('-');

    if (sep1 == 0 || sep1 == sep2 || sep1 == sep2 - 1 || sep2 == key.size() - 1)
        return (0);


    std::string year = key.substr(0, sep1);
    std::string month = key.substr(sep1 + 1, sep2 - sep1 - 1);
    std::string day = key.substr(sep2 + 1, key.size());

    if (month.size() != 2 || day.size() != 2)
        return (0);
    
    int month_value = atoi(month.c_str());
    if (month_value < 1 || month_value > 12)
        return (0);

    bool is_leap_year = leap_calc(year);
    std::map<int, int> calendar = calendar_init(is_leap_year);

    int day_value = atoi(day.c_str());
    if (day_value < 1 || day_value > calendar[month_value])
        return (0);
    return (1);
}

int pars_input(std::string input_str)
{
    if (!check_format(input_str))
        return (0);

    std::string key = input_str.substr(0, input_str.find_first_of(' '));
    std::string value = input_str.substr(input_str.find_last_of(' ') + 1, input_str.size());

    if (!check_key(key))
    {
        std::cout << "Error: invalid date" << std::endl;
        return (0);
    }
    if (!check_value(value))
        return (0);

    return (1);
}

void read_input(char *filename)
{
    BitcoinExchange database;
    std::ifstream infile(filename);
    if (!infile)
        throw std::runtime_error("Error: could not open file");

    std::string file_line;
    std::getline(infile, file_line);
    while(std::getline(infile, file_line))
    {
        if (file_line == "date | value")
            continue ;
        if (!pars_input(file_line))
        {
            continue ;
        }
        int sep = file_line.find('|');

        std::string key = file_line.substr(0, sep - 1);
        std::string value = file_line.substr(sep + 2, file_line.size());

        std::string db_value;
        try {
            db_value = database.getfrom(key);
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
            continue;
        }

        double product = atof(value.c_str()) * atof(db_value.c_str());

        std::cout << key << " => " << value << " = " << product << std::endl;
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: could not open file" << std::endl;
        return (1);
    }
    std::map<std::string, std::string> input;
    try{
        read_input(av[1]);
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
        return (1);
    }

    return 0;
}