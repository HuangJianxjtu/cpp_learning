// Ex2_05.cpp
// using explicit type
#include <iostream>

using namespace std;

int main()
{
    const unsigned int feet_per_yard {3};
    const unsigned int inches_per_foot {12};
    double length {};   // decimal
    unsigned int yards {};
    unsigned int feet {};
    unsigned int inches {};

    cout<<"enter a length in yards as a decimal: ";
    cin>>length;
    
    // get the length as yards, feet, and inches
    yards = static_cast<unsigned int>(length);
    feet = static_cast<unsigned int>((length-yards)*feet_per_yard);
    inches = static_cast<unsigned int>(length*feet_per_yard*inches_per_foot)%inches_per_foot;

    cout<<length<<" yards converts to "
        <<yards<<" yards "
        <<feet<<" feet "
        <<inches<<" inches."<<endl;
    
    return 0;
}