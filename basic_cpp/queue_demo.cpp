#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<char> c_set;
    c_set.push('a');
    c_set.push('b');
    c_set.push('c');

    char s = c_set.front();
    cout<<s<<endl;
    s = c_set.back();
    cout<<s<<endl;

    c_set.pop();
    cout<<c_set.size()<<endl;

    bool flag = c_set.empty();
    cout<<flag<<endl;

    return 0;
}