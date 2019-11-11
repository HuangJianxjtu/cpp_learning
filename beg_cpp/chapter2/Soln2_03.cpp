#include <iostream>
using namespace std;
int main()
{
    int length, feet, inches;
    const int inches_per_foot {12};
    cout<<"please enter the int type length in inches:";
    cin>>length;

    feet = length/inches_per_foot;
    inches = length%inches_per_foot;

    cout<<"the length you input corresponds to "<<feet<<" feet "<<inches<<" inches."<<endl;

    return 0;
}