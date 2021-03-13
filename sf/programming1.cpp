#include <iostream>
#include <vector>

//顺丰视觉算法工程师笔试
//正确率82%

using namespace std;

// major function
bool isStandardX(vector<vector<char> > chars, int n)
{
    //judge the character, e.g. a b, x o
    vector<int> char_counting;
    int i, j;
    char a_tmp = chars[0][0];
    char b_tmp = chars[0][1];

    if(a_tmp != b_tmp) // 应该先判断a_tmp和b_tmp是否相等!正确率88%的原因应该是这个
    {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if ((i == j) | (i + j == n - 1)) //对角
                {
                    if (chars[i][j] != a_tmp) {
                        return false;
                    }
                } else {
                    if (chars[i][j] != b_tmp) {
                        return false;
                    }
                }
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}

bool isInSet(vector<char> set, char a)
{
    for(int i=0;i<set.size();i++)
    {
        if(a == set[i])
            return true;
    }
    return false;
}


int main()
{
    int t, num_tmp;
    int counting =0;
    char a_tmp;
    vector<int> n;
    vector<vector<vector<char> > > chars_set;

    // get the data
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>num_tmp;
        vector<vector<char> > chars;
        vector<char> char_;
        n.push_back(num_tmp);
        for(int j=0;j<num_tmp;j++)
        {
            for(int k=0;k<num_tmp;k++)
            {
                cin>>a_tmp;
                char_.push_back(a_tmp);
            }
            chars.push_back(char_);
            char_.clear();
        }
        chars_set.push_back(chars);
        chars.clear();
    }

    //judge
    for(int i=0;i<t;i++)
    {
        if(isStandardX(chars_set[i], n[i]))
        {
            counting++;
        }
    }

    cout<<counting;

    return 0;
}