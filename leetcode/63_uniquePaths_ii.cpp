#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n= obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1){
            return 0;
        } else{
            vector<vector<double>> f(m, vector<double>(n));
            for(int i=0;i<m;i++){
                bool flag = true;
                for(int j=m-1-i;j<m;j++){
                    if(obstacleGrid[j][n-1] == 1){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    f[i][0] = 1;
                }
            }
            for(int i=0;i<n;i++){
                bool flag = true;
                for(int j=n-1-i;j<n;j++){
                    if(obstacleGrid[m-1][j] == 1){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    f[0][i] = 1;
                }
            }
            for(int i=1;i<m;i++){
                for(int j=1;j<n;j++){
                    int flag = obstacleGrid[m-1-i][n-1-j];
                    if(flag == 0){
                        int fi,fj;
                        fi = obstacleGrid[m-i][n-1-j];
                        fj = obstacleGrid[m-1-i][n-j];
                        f[i][j] = (1-fi)*f[i-1][j] + (1-fj)*f[i][j-1];
                    }
                }
            }
            return int(f[m-1][n-1]);
        }
    }
};

int main(){
    vector<vector<int>> ob(3, vector<int>(3));
    ob[1][1] = 1;
    Solution s;
    cout<<s.uniquePathsWithObstacles(ob)<<endl;
    return 0;
}
