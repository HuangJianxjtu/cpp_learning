#include <iostream>
#include <string.h>

using namespace std;

class MyClass{
public:
    int a=1;
    const int b;
    int & c;
    MyClass():b(1), c(a){
        cout<<"construct class"<<endl;
    };
    ~MyClass(){
        cout<<"destruct class"<<endl;
    }
private:
    int p=2;
};

int main() {
    // MyClass s;
    auto *s = new MyClass();
    cout<<s->b<<endl;
    cout<<s->a<<endl;
    delete s;
    int nums[5]={1, 2, 3, 4, 5};
    for(auto i:nums){
        cout<<i<<" ";
    }
    return 0;
}