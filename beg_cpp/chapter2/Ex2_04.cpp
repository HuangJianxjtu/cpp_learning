// Ex2_04.cpp
// sizing a pond for happy fish
#include <iostream>
#include <cmath>
#include <iomanip>
using std::cout;
using std::cin;
using std::sqrt;

int main()
{
    // 2 square feet pond surface for every 6 inches of fish
    const double fish_factor {2.0/0.5};     // area per unit length of fish
    const double inches_per_foot {12.0};
    const double pi {3.14159265};
    
    double fish_count {};
    double fish_length {};

    cout<<"enter the number of fish you want to keep: ";
    cin>>fish_count;
    cout<<"enter the average fish length in inches: ";
    cin>>fish_length;
    fish_length /= inches_per_foot;     // convert to feet

    // calculate the required surface area
    double pond_area = {fish_count*fish_length*fish_factor};

    // calculate the pond diameter from the area
    double pond_diameter {2.0*sqrt(pond_area/pi)};

    cout<<"\nPond diameter requred for "<< fish_count <<" fish is "<<std::setprecision(2)<<pond_diameter<<" feet.\n";
}