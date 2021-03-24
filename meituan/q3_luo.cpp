#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float t_min = 100000000.0;

void dfs(vector<int> a_set_in, int level, int index, vector<int> res_in, int depth, int c){
    if(level == depth){
        float t = 0.0;
        int vol_sum =0, vol_sum_a=0;
        for(auto it:res_in){
            vol_sum += it;
        }
        for(auto it:a_set_in){
            vol_sum_a += it;
        }
        if(vol_sum == vol_sum_a){ //所有奶茶要喝完
            int v = *max_element(res_in.begin(), res_in.end());
            t = float(v)/float(c);
            if(t<t_min){
                t_min = t;
            }
        }
        return;
    }

    for(int i=0;i<a_set_in.size();i++){
        int vol_tmp = 0;
        if(index+i < a_set_in.size()) {  //数组没有越界
            for(int j=index; j<index+i;j++){
                vol_tmp += a_set_in[j];
            }
            index = index+i;
            res_in.push_back(vol_tmp);
            dfs(a_set_in, level+1, index, res_in, depth, c); //向下递归
            index = index-i; //向上回溯
            res_in.pop_back();
        } else{
            return;
        }
    }
}

int main(){
    int n=0, m=0, c=0;
    vector<int> a_set;
    vector<bool> checked;
    vector<int> res;
    cin>>n>>m>>c;
    for(int i=0;i<n;i++){
        int it=0;
        cin>>it;
        a_set.push_back(it);
        checked.push_back(false);
    }

    dfs(a_set, 0, 0, res, m, c);

    cout<<t_min<<endl;
    return 0;
}