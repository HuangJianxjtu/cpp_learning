#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, p = 0;
    vector<int> res;
    cin >> n >> p;
    int len = 2 * n;
    for (int i = 0; i < 2 * n; i++) {
        int tmp = 0;
        cin >> tmp;
        res.push_back(tmp);
    }
    sort(res.begin(), res.end());
    // TODO:
    // for_each(res.begin(), res.end(), [](const double d) { cout << d << " "; });
    // cout << endl;
    int midIndex = res.size() / 2 - 1;
    int estimateUp = 0, estimateDown = 0;
    if (p > 50) {
        for (int i = 0; i <= midIndex; i++) {
            estimateUp += (p * res[len - i - 1]);
            estimateDown += ((100 - p) * res[i]);
        }
    } else {
        for (int i = 0; i < len - 1; i=i + 2) {
            estimateUp += (p * res[i + 1]);
            estimateDown += ((100 - p) * res[i]);
        }
    }
    int result = estimateUp + estimateDown;
    if (result % 100 == 0) {
        cout << result / 100 << endl;
    } else {
        cout << result << "%" << endl;
    }
    return 0;
}