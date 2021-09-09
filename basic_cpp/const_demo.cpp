#include <iostream>

using namespace  std;

// 参考：https://blog.csdn.net/luoweifu/article/details/45600415

class myData{
public:
    myData(int v) : value(0){
        value = v;
    }
    int value;
};

//const在函数中的应用:希望传入一个对象，又不想让函数体修改这个对象。
void dealWith(const myData& d){
    cout<<d.value<<endl;
    // d.value = 88;  //错误，data是常量引用，不能改变其邦定的对象
}

void dealWith1(const myData* d){
    cout<<d->value<<endl;
    // d->value = 66;
}


int main(){
    // const T, 定义一个常量，声明的同时必须进行初始化。一旦声明，这个值将不能被改变。
    int i =0;
    const int constInt1 = 1;
    const int constInt2 = i;
    // constInt1 = 2;   // 错误，常量值不能改变
    // const int constInt3;    //错误，未被初始化

    // const T*, 指向常量的指针，不能用于改变其所指向的对象的值
    const int* pInt1;
    pInt1 = &constInt1;
    cout << *pInt1 <<endl;
    const int* pInt2 = &constInt2;
    // *pInt1 = 2;   //pInt1不能改变其所指向对象的值
    pInt1 = &constInt2; //但pInt1可以改变其本身的值,即指针指向

    myData d(99);
    d.value = 55;

    dealWith(d);
    dealWith1(&d);

    return 0;
}
