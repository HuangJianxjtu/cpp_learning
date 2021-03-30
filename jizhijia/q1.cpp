#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 典型错误与不足：1.没有考虑到int相加会溢出；2.char和数字之前的转换不熟

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        // write code here
        int num1, num2,sum;
        string result_str;
        num1 = stoi(s);
        num2 = stoi(t);
        sum = num1+num2;
        result_str = num2str(sum);
        return result_str;
    }
    string num2str(int num){
        int remain, res_int;
        vector<char> res;
        char c;
        while (true){
            if(num/10 >= 1){
                remain = num%10;
                res_int = num/10;
                num = (num-remain)/10;

                c = int_2_c(remain);
                res.push_back(c);
            } else{
                c = int_2_c(num);
                res.push_back(c);
                break;
            }
        }
        int l = res.size();
        string res_str = "";
        // res_str.resize(l);
        for(int i=l-1; i>=0;i--){
            // res_str[l-1-i] = res[i];
            res_str += res[i];
        }
        return res_str;
    }
    char int_2_c(int i){
        char c;
        // switch (i) {
        //     case 0: return '0';
        //     case 1: return '1';
        //     case 2: return '2';
        //     case 3: return '3';
        //     case 4: return '4';
        //     case 5: return '5';
        //     case 6: return '6';
        //     case 7: return '7';
        //     case 8: return '8';
        //     case 9: return '9';
        // }
        switch (i) {
            case 0:
                c = '0';
                break;
            case 1:
                c = '1';
                break;
            case 2:
                c = '2';
                break;
            case 3:
                c = '3';
                break;
            case 4:
                c = '4';
                break;
            case 5:
                c = '5';
                break;
            case 6:
                c = '6';
                break;
            case 7:
                c = '7';
                break;
            case 8:
                c = '8';
                break;
            case 9:
                c = '9';
                break;
        }
        return c;
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
