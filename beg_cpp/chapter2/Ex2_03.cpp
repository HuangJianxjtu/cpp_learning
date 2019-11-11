// Ex2_03.cpp
// Writing floating-point properties to cout
#include <iostream>
#include <cfloat>

using namespace std;

int main()
{
    cout<<"the mantissa for type float has "<<FLT_MANT_DIG<<" bits."<<endl;
    cout<<"the maximum value of type float is "<<FLT_MAX<<endl;
    cout<<"the minimum non-zero value of type float is "<<FLT_MIN<<endl;

    return 0;
}