#include <iostream>

using namespace std;

int main()
{
    //接受输入
    int n, m;
    cin>>n>>m;
    int nums[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>nums[i][j];
        }
    }

    //翻转数组并输出
    int out_nums[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            out_nums[i][j] = nums[j][i];
            cout<<out_nums[i][j]<<" ";
        }
        if(i<m-1)
        {
            cout<<endl;
        }
    }


    return 0;
}