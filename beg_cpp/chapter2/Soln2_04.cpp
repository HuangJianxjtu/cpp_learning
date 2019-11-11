#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float h, d_feet, d_inches, angle,h_tree;
    const int inches_per_foot {12};

    cout<<"please enter h in inches:";
    cin>>h;
    cout<<"please enter d in feet and inches:(format:feet inches)";
    cin>>d_feet>>d_inches;
    cout<<"please enter angle in degrees:";
    cin>>angle;

    h_tree = h+(d_feet*inches_per_foot+d_inches)*tan(angle*M_PI/180.0); // inches
    h_tree /= inches_per_foot;  // feet

    cout<<"the height of tree is "<<h_tree<<" feet."<<endl;

    return 0;
}