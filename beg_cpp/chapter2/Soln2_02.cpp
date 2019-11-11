#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const float pi {3.14159265};
    float radius {},area {};
    int n {};
    cout<<"please enter the radius of the circle: ";
    cin>>radius;
    cout<<"please enter the number of presicion, an integer: ";
    cin>>n;
    area = pi*radius*radius;
    cout<<setprecision(n)<<"the area of circle is: "<<area<<endl;

    return 0;    
}