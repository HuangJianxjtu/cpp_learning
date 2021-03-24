#include <iostream>
#include <vector>

using namespace std;

//c++从vector中删除指定元素
// https://blog.csdn.net/qq_20087731/article/details/109031596

int main() {
    vector<int> nums = {1, 2, 3, 4};

    // nums.erase(3);

    for(auto iter=nums.begin(); iter!=nums.end();iter++){
        // if(*iter == 3){
        //     nums.erase(iter);
        // }
        if(iter == nums.begin()+2)
            nums.erase(iter);
    }

    for(auto it:nums) {
        cout<<it<<endl;
    }
    return 0;
}