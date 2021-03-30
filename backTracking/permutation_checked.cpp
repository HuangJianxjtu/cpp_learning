#include <iostream>
#include <vector>

using namespace std;

// 全排列问题
// TODO：leetcode中的题目
void dfs(string ss, bool chars_b[], int level, vector<char> res) {
    //截止条件
    int length = ss.length();
    if (level == length) {
        for (int kk = 0; kk < res.size(); kk++) {
            cout << res[kk] << ' ';
        }
        cout << endl;
        res.clear();
        return;
    }
    //遍历候选节点
    for (int i = 0; i < length; i++) {
        char c = ss[i];
        if (!chars_b[i]) {
            res.push_back(c);
            chars_b[i] = true;
            dfs(ss, chars_b, level + 1, res);  //向下递归
            chars_b[i] = false;
            res.pop_back();   //回溯到上一个节点
        }
    }
}

int main() {
    string ss = "abc";
    int length = ss.length();
    bool chars_b[length];
    for (int i = 0; i < length; i++) {
        chars_b[i] = false;
    }
    vector<char> res;

    dfs(ss, chars_b, 0, res);

    return 0;
}