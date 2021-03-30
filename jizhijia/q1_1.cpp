#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 计算两个数之和,数字坑可能很大！（题型：两大数相加）
// 输入例子：
// "222" "888"
// "1234" "223"
// "9999999999999999" "1"

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        int max_length, min_length;
        vector<char> max_str_re, min_str_re,result_re; //倒序存储
        string max_str, min_str, result_str="";
        if(s.length() > t.length()){
            max_length = s.length();
            min_length = t.length();
            max_str = s;
            min_str = t;
        } else{
            max_length = t.length();
            min_length = s.length();
            max_str = t;
            min_str = s;
        }
        for(int i=max_length-1;i>=0;i--){
            max_str_re.push_back(max_str[i]);
        }
        for(int i=min_length-1;i>=0;i--){
            min_str_re.push_back(min_str[i]);
        }

        int beyond=0, bit_max = 0, bit_min=0, sum_tmp=0;
        for(int i = 0;i<max_length+1;i++){
            if(i<min_length){ //相加未结束
                sum_tmp = (max_str_re[i] - '0') + (min_str_re[i]-'0')+beyond;
                if(sum_tmp >9){
                    beyond = 1;
                    sum_tmp = sum_tmp-10;
                } else{
                    beyond = 0;
                }
                result_re.push_back(sum_tmp+'0');
            } else if (i<max_length){
                sum_tmp = (max_str_re[i] - '0')+beyond;
                if(sum_tmp >9){
                    beyond = 1;
                    sum_tmp = sum_tmp-10;
                } else{
                    beyond = 0;
                }
                result_re.push_back(sum_tmp+'0');
            } else{//判断末尾有无进1
                if(beyond==1){
                    result_re.push_back('1');
                }
            }
        }

        for(int i=result_re.size()-1;i>=0;i--){ //正序存储
            result_str += result_re[i];
        }
        return result_str;
    }
};

int main(){
    string str1,str2, result;
    cin>>str1>>str2;

    Solution s;

    result = s.solve(str1, str2);

    cout<<result<<endl;

    return 0;
}
