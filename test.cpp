#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution{
public:
    int majorityElement(vector<int>& nums){
        unordered_map<int, int> counting;
        int majority, maxNum=0;
        for(int i:nums)
        {
            ++counting[i];
            if(counting[i]>maxNum)
            {
                maxNum = counting[i];
                majority = i;
            }
        }
        return majority;
    }
};

class MySolution {
public:
    int majorityElement(vector<int>& nums) {
        int i,j,maxIndex,maxNum;
        vector<int> couting, value;
        // 计数
        for(i=0;i<nums.size();i++)
        {
            if(!isInSet(nums[i], value))
            {
                value.push_back(nums[i]);
                couting.push_back(1);
            }
            else
            {
                for(j=0;j<value.size();j++)
                {
                    if(value[j]==nums[i])
                    {
                        couting[j]+=1;
                        break;
                    }
                }
            }
        }
        //找最大值
        maxNum = 0;
        maxIndex = 0;
        for(i=0;i<couting.size();i++)
        {
            if(couting[i] > maxNum)
            {
                maxNum = couting[i];
                maxIndex = i;
            }
        }
        return value[maxIndex];
    }
    bool isInSet(int item, vector<int> set)
    {
        int i;
        for(i=0;i<set.size();i++)
        {
            if(set[i]==item)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<int> nums{1,2, 2,2,3};
    Solution s;
    cout<<s.majorityElement(nums)<<endl;
    return 0;
}