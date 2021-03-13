#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int getMost(vector<int>& nums)
{
    map<int, int> m;
    for(int i=0;i<nums.size();i++)
    {
        auto ret = m.insert({nums[i], 1});
        if(!ret.second)
        {
            ++ret.first->second;
        }
    }
    // sort(nums.begin(), nums.end());
    int count = m.begin()->second;
    int result = m.begin()->first;
    for(auto map_it = m.begin();map_it!=m.end(); ++map_it)
    {
        if(map_it->second > count)
        {
            count = map_it->second;
            result = map_it->first;
        }
    }
    return result;
}

int main()
{
    int n=0, k=0;
    cin>>n>>k;
    vector<int> arr;
    int temp=0;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        arr.emplace_back(temp);
    }
    for(int i=0;i<=n-k;i++)
    {
        vector<int> source(arr.begin()+i, arr.begin()+i+k);
        cout<<getMost(source)<<endl;
    }
}