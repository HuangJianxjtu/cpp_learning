#include <iostream>
#include <vector>

// leetcode原题240

using namespace std;

class Solution {
public:
    vector<int> findElement(vector<vector<int> > mat, int n, int m, int x) {
        // write code here
        std::vector<int> result;
        for(int i=0;i<n;i++){
            int low = 0;
            int mid = 0;
            int high = m-1;
            while (low<=high){
                mid = (low+high)/2;
                if(x == mat[i][mid]){
                    result.push_back(i);
                    result.push_back(mid);
                    return result;
                } else if(x>mat[i][mid]){
                    low = mid+1;
                } else{
                    high = mid-1;
                }
            }
        }
        return result;
    }
};