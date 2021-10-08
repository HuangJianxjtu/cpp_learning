#include <iostream>
using namespace std;

class TestClass{
public:
    //必须在初始化列表中初始化的引用和const成员变量！！！
    TestClass(int &in_t, int in_s):t(in_t),s(in_s){
        cout << "constructor"<<endl;
    }
    int get_t() const {
        return t;
    }
private:
    int &t;
    const int s;
};
int main(){
    int i=0;
    TestClass t(i,2);
    cout<<t.get_t()<<endl;
    i=3;
    cout<<t.get_t()<<endl;
    return 0;
}