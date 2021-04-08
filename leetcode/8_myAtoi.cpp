#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        bool begin_reading = false;
        int flag = 1; //正负号
        vector<int> res_nums;
        for(auto s_bit:s){
            if(s_bit == ' ' && !begin_reading){
                continue;
            } else if(s_bit == '-' && !begin_reading){
                flag = -1;
                begin_reading = true;
            } else if(s_bit == '+' && !begin_reading){
                flag = 1;
                begin_reading = true;
            } else if(s_bit >= '0' && s_bit <= '9'){
                begin_reading = true;
                int bit_int;
                bit_int = s_bit - '0';
                res_nums.push_back(bit_int);
            } else{
                break;
            }
        }
        int l = res_nums.size();
        double result_db = 0;
        int result = 0;
        for(int i=0;i<l;i++){
            result_db += res_nums[i]*pow(10, l-1-i);
        }
        result_db *= flag;
        if(result_db > pow(2, 31)-1){
            result =  pow(2, 31)-1;
        } else if( result_db < -1*pow(2, 31)){
            result =  -1*pow(2, 31);
        } else{
            result = int(result_db);
        }
        return result;
    }
};

int main(){
    string str = "-91283472332";
    int res_str;
    Solution s;
    res_str = s.myAtoi(str);
    cout<<res_str<<endl;
    return 0;
}