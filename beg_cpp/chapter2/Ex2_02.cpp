// Ex2_02.cpp
// Converting distances
#include <iostream>

int main()
{
    unsigned int yards {}, feet {}, inches {};

    // convert a distance in yards, feet, and inches to inches
    std::cout<<"enter a distance as yards, feet, and inches"
             <<"with the three values separated by spaces:"
             <<std::endl;
    std::cin>>yards>>feet>>inches;

    const unsigned int feet_per_yard {3U};
    const unsigned int inches_per_foot {12U};
    unsigned int total_inches {};
    total_inches = inches + inches_per_foot*(yards*feet_per_yard+feet);
    std::cout<<"the distances corresponds to "<<total_inches<<" inches.\n";

    // convert a distances in inches to yards feet and inches
    std::cout<<"enter a distance in inches:";
    std::cin>>total_inches;
    feet = total_inches/inches_per_foot;
    inches = total_inches%inches_per_foot;
    yards = feet/feet_per_yard;
    feet = feet%feet_per_yard;
    std::cout<<"the distance corresponds to "
             <<yards<<" yards "
             <<feet<<" feet "
             <<inches<<" inches."<<std::endl;
    
    return 0;
}