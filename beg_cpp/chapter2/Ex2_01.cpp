// Ex2_01.cpp
// Writing values of variables to cout
#include <iostream>

int main()
{
    int apple_count {15};
    int orange_count {5};
    int total_fruit {apple_count+orange_count};

    std::cout<<"the value of apple_count is "<<apple_count<<std::endl;
    std::cout<<"the value of orange_count is "<<orange_count<<std::endl;
    std::cout<<"the value of total_fruit is "<<total_fruit<<std::endl;

    return 0;
}