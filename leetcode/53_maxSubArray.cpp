#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int max_sum, dp, dp_last;
        dp_last = 0;
        max_sum = nums[0];
        for (auto it:nums) {
            dp = max(dp_last + it, it);
            max_sum = max(max_sum, dp);
            dp_last = dp;
        }
        return max_sum;
    }
};

int main(){
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    cout<<"max sum of the contiguous subarray:"<<s.maxSubArray(nums)<<endl;
    return 0;
}