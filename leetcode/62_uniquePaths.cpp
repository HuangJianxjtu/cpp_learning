#include <iostream>
#include <vector>

using namespace std;

// 使用动态规划解题

class Solution1 { // 递归形式
    // leetcode提交后显示超时
    // 原因分析：函数调用的开销导致的。调用一个函数前需要很多准备工作，如准备局部变量的存储空间、搞定函数参数等
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1){
            return 1;
        } else{
            return uniquePaths(m-1, n)+uniquePaths(m, n-1);
        }
    }
};

class Solution { //for形式
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m, vector<int>(n));
        for(int i=0;i<m;i++){
            f[i][0] = 1;
        }
        for(int i=0;i<n;i++){
            f[0][i] = 1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                f[i][j] = f[i-1][j]+f[i][j-1];
            }
        }
        return f[m-1][n-1];
    }
};

int main(){
    Solution s;
    Solution1 s1;
    cout<<s.uniquePaths(3, 2)<<endl;
    cout<<s1.uniquePaths(3, 2)<<endl;
}