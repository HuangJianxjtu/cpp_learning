#include <iostream>

using namespace std;

int main(int argc, char **argv){ //argc(参数计数)和argv(参数向量)
    //默认第一个参数是可执行文件；本程序在clion中预设了三个参数arg1, arg2, arg3. 一共4个参数
    //argc=4
    cout<<"Have "<<argc<<" arguments"<<endl;
    for (int i = 0; i < argc; ++i) { //
        cout<<argv[i]<<endl;
    }
}
