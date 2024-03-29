#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 2021华为软件算法笔试题，第三题,LUO

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