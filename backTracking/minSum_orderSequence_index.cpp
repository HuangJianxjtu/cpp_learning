#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 此题是用index来做；一开始用checked导致耽误时间；应该总结index和checked的应用场景
// index一般用在顺序子序列中
// checked一般用在排列等非顺序情形中

// 2021华为软件算法笔试题，第三题
// 题目描述:
// 一个工厂有m个工人，共同负责一条生产线的生产活动。在生产线的最末端有个检测装置，会对前面生产的产品进行检测，对于生产有问题的产品会进行扣分，
// 它会给出一组非负的扣分的分值。这些扣分要切分成连续的m组分摊到m个工人身上，每个人的扣分就是分摊到他身上的扣分和。你作为生产线的工段长要保正
// 每个二人分摊到的扣分都尽可能的少，输出切分后的最大扣分值和具体扣分子数组。
//
// 输入描述:
// 输入第一行表示生产线工人的个数，工人数量范围为(1,100)
// 第二行表示扣分项数组，扣分项数范围为(1,1000)
//
// 输出描述:
// 输出第一行表示分摊后工人中最多的扣分值
// 输出第二行表示分摊后的和扣分子数组，如分摊后两个数组为[5] [4,1]，输出需要保持输入扣分项相对顺序
//
// 示例1
// 输入：
// 3
// 5 4 1 2 4
// 输出
// 6
// [5][4,1][2,4]

vector<vector<int>> result_global;

int max_num_global = 10000;
void dfs(vector<int> numSet_in, int index, int level, int depth, vector<vector<int>> result) {
    int length = numSet_in.size();
    if(level == depth) {
        if(index == length){   //所有数要用完
            vector<int> sum_set;
            for(auto set:result){
                int sum_tmp=0;
                for(auto it:set){
                    sum_tmp += it;
                }
                sum_set.push_back(sum_tmp);
            }
            sort(sum_set.begin(), sum_set.end());
            int max_num_tmp = sum_set[sum_set.size()-1];
            if(max_num_tmp < max_num_global){
                max_num_global = max_num_tmp;
                result_global = result;
            }
        }
        return;
    }
    vector<int> nums_one_person;
    for(int i=0;i<numSet_in.size();i++){
        if(index < length){
            nums_one_person.push_back(numSet_in[index + i]);
            index = index + nums_one_person.size();
            result.push_back(nums_one_person);
            dfs(numSet_in, index, level+1, depth, result);
            result.pop_back();
            index = index - nums_one_person.size();
        } else{
            return;
        }
    }
}
int main() {
    int n = 0, tmp;
    vector<int> numSet;
    vector<bool> checked;
    vector<vector<int>> res;
    cin>>n;
    while (true){
        cin>>tmp;
        numSet.push_back(tmp);
        checked.push_back(false);
        if(cin.get() == '\n')   break;
    }

    dfs(numSet, 0, 0, n, res);

    cout<<max_num_global<<endl;
    for(auto it:result_global){
        cout<<"[";
        for(int i=0;i<it.size();i++){
            cout<<it[i];
            if(i<it.size()-1){
                cout<<",";
            }
        }
        cout<<"]";
    }
    return 0;
}