#include <iostream>
#include <vector>
#include <math.h>

//2021.3.16, 美团面试,现场代码题
//【IP字符串转换】输入一串数字字母(对应一个ip), 输出ip
//e.g., input:19216801, output:192.168.0.1
// leetcode原题, No.93
// 知乎文章讲解回溯算法(https://zhuanlan.zhihu.com/p/166411078)
// B站讲解视频(https://www.bilibili.com/video/BV1qE411E7di?from=search&seid=4738241862476715193)

using namespace std;

int chars_to_int(vector<char> input_chars) {
    string s;
    for (int i = 0; i < input_chars.size(); i++) {
        s += input_chars[i];
    }
    return stoi(s);
}

void dfs(string ip_str, int index, int level, vector<vector<char>> res) {
    int length = ip_str.length();

    //截止条件
    if (level == 4) {
        //判断4个ip段是否合法且四个ip段长度等于输入字符串长度
        bool valid_flag = true;
        int res_len=0;
        for (int i = 0; i < res.size(); i++) {
            if(chars_to_int(res[i])<0 | chars_to_int(res[i])>255) {
                valid_flag = false;
                break;
            }
            if(res[i].size()>1 && res[i][0]=='0'){  //不能出现0在前面的情况, e.g. "01"
                valid_flag = false;
                break;
            }
            res_len += res[i].size();
        }
        if(res_len != length){
            valid_flag = false;
        }

        //若4段ip都合法,则输出结果,结束程序
        if(valid_flag) {
            for(int i=0;i<res.size();i++){
                cout<<chars_to_int(res[i]);
                if(i < res.size()-1){
                    cout<<",";
                }
            }
            cout<<endl;
            // TODO: 结束程序
        }
        return;
    }

    //遍历候选节点
    for(int i=1; i<=3;i++){
        vector<char> ip_seg_str;
        for(int j=0;j<i;j++){
            if(index < length){
                ip_seg_str.push_back(ip_str[index]);
                index++;
            } else{
                return; //已经超出检索范围,结束此分支
            }
        }
        res.push_back(ip_seg_str);
        dfs(ip_str, index, level+1, res); //向下递归
        //回溯到上一个节点
        res.pop_back();
        index = index-i;
    }
}

int main()
{
    string input_str;
    cin>>input_str;

    vector<vector<char>> result;

    dfs(input_str, 0, 0, result);

    return 0;
}