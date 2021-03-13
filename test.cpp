#include <iostream>

using namespace std;

void print_hello()
{
    cout<<"hello world!"<<endl;
}

void print_hello(int i)
{
    cout<<"hello world 2!"<<endl;
}

int main()
{
    print_hello(2);
    return 0;
}