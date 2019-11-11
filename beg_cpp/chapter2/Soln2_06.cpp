#include <iostream>
using namespace std;

int main()
{
    float w,h_feet,h_inches,h, bmi;
    const float kilogram_to_lbs {2.2}, foot_to_meter {0.3048}, inches_per_foot {12.0};
    cout<<"please enter weight in pounds:";
    cin>>w;
    cout<<"please enter height in feet and inches(format:feet inches):";
    cin>>h_feet>>h_feet;
    h = h_feet+h_inches/inches_per_foot;    // feet
    h /= foot_to_meter;     // meter
    w /= kilogram_to_lbs;   // kilogram
    bmi = w/(h*h);
    cout<<"bmi="<<bmi<<endl;
}