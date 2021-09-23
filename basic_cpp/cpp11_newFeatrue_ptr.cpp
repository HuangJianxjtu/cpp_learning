#include <iostream>
#include <memory>
using namespace std;

class Test{
public:
    Test(){
        cout<<"Constructing Test()"<<endl;
    }
    ~Test(){
        cout<<"Destructing Test()"<<endl;
    }
    void print_hello(){
        cout<<"hello world"<<endl;
    }
};

int main(){
    shared_ptr<Test> t = make_shared<Test>();
    t->print_hello();
    Test* tt = new Test();
    tt->print_hello();
    return 0;
}