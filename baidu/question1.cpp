#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_estimate = 0;

int my_max(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

int my_min(int x, int y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

void dfs(vector<int> nums_in, bool checked[], int level, vector<int> res_seq, int p) {
    int depth = nums_in.size();
    //截止条件
    if (level == depth) {
        int estimate = 0;
        for (int i = 0; i < depth; i = i + 2) {
            estimate += p * my_max(res_seq[i], res_seq[i + 1]) + (100 - p) * my_min(res_seq[i], res_seq[i + 1]);
        }
        if (estimate > max_estimate) {
            max_estimate = estimate;
        }
        res_seq.clear();
        return;
    }
    //编列所有候选节点
    for (int i = 0; i < nums_in.size(); i++) {
        if (!checked[i]) {
            res_seq.push_back(nums_in[i]);
            checked[i] = true;
            dfs(nums_in, checked, level + 1, res_seq, p); //向下递归
            res_seq.pop_back();  //遍历同层节点
            checked[i] = false;
        }
    }
}

int main() {
    int n = 0, p = 0;
    vector<int> res;
    int len = 2 * n;
    cin >> n >> p;
    bool checked[len];
    for (int i = 0; i < 2 * n; i++) {
        int tmp = 0;
        cin >> tmp;
        res.push_back(tmp);
        checked[i] = false;
    }

    vector<int> res_seq;

    dfs(res, checked, 0, res_seq, p);

    if (max_estimate % 100 == 0) {
        cout << max_estimate / 100 << endl;
    } else {
        cout << max_estimate << "%" << endl;
    }

    return 0;
}