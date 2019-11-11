// Ex2_06.cpp
// Finding maximum and minimum values for data types
#include <limits>
#include <iostream>

using namespace std;

int main()
{
    cout<<"the range for type short is from "<<numeric_limits<short>::min()<<" to "<<numeric_limits<short>::max()<<endl;
    cout<<"the range for type int is from "<<numeric_limits<int>::min()<<" to "<<numeric_limits<int>::max()<<endl;
    cout<<"the range for type long is from "<<numeric_limits<long>::min()<<" to "<<numeric_limits<long>::max()<<endl;
    cout<<"the range for type float is from "<<numeric_limits<float>::min()<<" to "<<numeric_limits<float>::max()<<endl;
    cout<<"the range for type double is from "<<numeric_limits<double>::min()<<" to "<<numeric_limits<double>::max()<<endl;
    cout<<"the range for type long double is from "<<numeric_limits<long double>::min()<<" to "<<numeric_limits<long double>::max()<<endl;

    return 0;
}