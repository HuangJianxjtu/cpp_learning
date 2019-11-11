#include <iostream>

using namespace std;

int main()
{
    const float pi {3.14159265};
    float radius {},area {};
    cout<<"please enter the radius of the circle: ";
    cin>>radius;
    area = pi*radius*radius;
    cout<<"the area of circle is: "<<area<<endl;

    return 0;    
}