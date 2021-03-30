#include <iostream>
#include <string.h>

using namespace std;

int a=0;

// strlen所作的仅仅是一个计数器的工作，它从内存的某个位置（可以是字符串开头，中间某个位置，甚至是某个不确定的内存区域）开始扫描，
// 直到碰到第一个字符串结束符'\0'为止，然后返回计数器值。

int main() {
    char str[10] = "China\0";
    string str1 = "123", str2, str3;
    int num=345;

    str3 = to_string(num);
    str2 = str1[0];
    cout<<strlen(str)<<endl;
    cout<<sizeof(1)<<endl;
    cout<<stoi(str2)<<endl;
    cout<<str3<<endl;
    return 0;
}