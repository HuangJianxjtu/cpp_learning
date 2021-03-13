#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> res;
    string cache, number = "";
    getline(cin, cache);
    const int sz = cache.length();
    for (int i = 0; i < sz; i++)
    {
        if(cache[i] >= '0' && cache[i] <='9')
        {
            number += cache[i];
        }
        else
        {
            if(number!="")
            {
                res.push_back(number);
            }
            number = "";
        }
    }
    if(number != "")
    {
        res.push_back(number);
    }

    for(string& s:res)
    {
        int i=0;
        for(;i<s.length();++i)
        {
            if(s[i] != '0')
            {
                break;
            }
        }
        if(i == s.length())
        {
            s="0";
        }
        else{
            s = s.substr(i, s.length()-i);
        }
    }
    sort(res.begin(), res.end(), [](const string& s1, const string& s2) {
        if(s1.length() < s2.length())
        {
            return true;
        }
        else if (s1.length() > s2.length())
        {
            return false;
        }
        return s1<s2;
    });

    for(const string& n:res)
    {
        cout<<n<<endl;
    }
    return 0;
}
