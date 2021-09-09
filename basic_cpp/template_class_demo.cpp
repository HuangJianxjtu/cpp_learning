#include <iostream>

using namespace std;

// template with default params: int & double
template<typename T1=int, typename T2=double>
class HoldPair{
private:
    T1 value1;
    T2 value2;
public:
    // constructor
    HoldPair(const T1& val1, const T2& val2)
        :value1(val1), value2(val2) {};

    const T1& GetFirstValue() const{
        return value1;
    }
    const T2& GetLastValue() const{
        return value2;
    }
};

int main(){
    HoldPair<> p1(300, 10.01); // use default datatype
    cout << "the first object contain"<<endl;
    int i;
    i = p1.GetFirstValue();
    cout << "value 1: "<<p1.GetFirstValue()<<endl;
    cout << "value 2: "<<p1.GetLastValue()<<endl;

    // NOTE: 如果没有默认数据类型，则必须指定模板的数据类型
    HoldPair<int, char*> p2(100, "hello template class");
    cout << "the second object contain"<<endl;
    cout << "value 1: "<<p2.GetFirstValue()<<endl;
    cout << "value 2: "<<p2.GetLastValue()<<endl;
    return 0;
}