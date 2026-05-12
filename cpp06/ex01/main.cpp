#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data *data = new Data();
    data->value = 1;

    uintptr_t value = Serializer::serialize(data);

    Data *new_data = Serializer::deserialize(value);

    std::cout << "Data value: " << data->value << std::endl
        << "New_data value: " << new_data->value << std::endl;

    return (0);
}