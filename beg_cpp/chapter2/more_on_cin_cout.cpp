// input and output in hex
#include <iostream>

using namespace std;

int main()
{
    short int hex_c;
    cout<<"size: "<<sizeof(hex_c)<<" bytes"<<endl;
    cout<<"please enter the numer in hex: ";
    cin>>hex>>hex_c;        // e.g  0x0b, AB, 0c
    cout<<hex<<"the number you input is: "<<hex_c<<endl;

    return 0;
}
