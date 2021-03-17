#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int chars_to_int(vector<char> chars_in){
    int result=0;
    string ss;
    for(int i=0;i<chars_in.size();i++){
        ss[i] = chars_in[i];
    }
    result = stoi(ss);
    return result;
}

int main(){
    string str_input;
    cin>>str_input;

    vector<vector<char>> res_chars;
    vector<int> res_nums;
    vector<char> one_num_chars_tmp;

    for(int i=0;i<str_input.length();i++){
        if(str_input[i]>='0' && str_input[i]<='9'){
            one_num_chars_tmp.push_back(str_input[i]);
            if(i == str_input.length()-1){
                res_chars.push_back(one_num_chars_tmp);
                one_num_chars_tmp.clear();
            }
        } else{
            if(!one_num_chars_tmp.empty() && !one_num_chars_tmp.empty()){
                res_chars.push_back(one_num_chars_tmp);
                one_num_chars_tmp.clear();
            }
        }
    }

    for(int i=0;i<res_chars.size();i++){
        if(res_chars[i][0] == '0' && res_chars[i].size()>1){
            vector<char> c_tmp;
            for(int j=1;j<res_chars[i].size();j++){
                c_tmp.push_back(res_chars[i][j]);
            }
            res_nums.push_back(chars_to_int(c_tmp));
        } else{
            res_nums.push_back(chars_to_int(res_chars[i]));
        }
    }

    sort(res_nums.begin(), res_nums.end());

    for(auto item:res_nums){
        cout<<item<<endl;
    }
    return 0;
}