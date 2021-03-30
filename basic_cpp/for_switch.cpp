#include <iostream>

using namespace std;

// switch(c)中的c必须是整型(int)或者枚举类型

int main(){
    int c_int = 1;
    double c_double = 1.0;  // 非法(invalid)
    char c_char = 'a';
    unsigned c_unsigned = 1;
    switch (c_char) {
        case 'c':
            cout<<"case 1"<<endl;
            break;
        case 'a':
            cout<<"case 2"<<endl;
            break;
    }
    return 0;
}