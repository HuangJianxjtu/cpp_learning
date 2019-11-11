#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cout<<"please input two different positvive integer:";
    cin>>a>>b;
    if(a>b)
        cout<<"the bigger:"<<a<<","<<"the smaller:"<<b<<endl;
    else
        cout<<"the bigger:"<<b<<","<<"the smaller:"<<a<<endl;
}