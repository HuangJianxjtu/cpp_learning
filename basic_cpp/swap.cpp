#include <iostream>

using namespace  std;

//值传参
template<typename T>
void value_swap(T &a, T &b){
    T c;
    c = a;
    a = b;
    b = c;
}

//指针传参
template<typename T>
bool pointer_swap(T *a, T *b){
    if(a == nullptr||b== nullptr){
        return false;
    }
    T c;
    c = *a;
    *a = *b;
    *b = c;
    return true;
}

int main(){
    float a=1, b=2, c=3,d=4;
    cout<<"before swap, a="<<a<<", "<<"b="<<b<<endl;
    value_swap(a, b);
    cout<<"after swap, a="<<a<<", "<<"b="<<b<<endl;

    cout<<"before swap, c="<<c<<", "<<"b="<<c<<endl;
    pointer_swap<float>(&c, &d);  //NOTE:显式地声明类型。这对于模板函数是非必要的，而对于模板类是必要的
    // pointer_swap(&c,&d);
    cout<<"after swap, c="<<c<<", "<<"b="<<c<<endl;
    return 0;
}