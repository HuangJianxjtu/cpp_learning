#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> res;
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
                res.push_back(std::stoi(number));
            }
            number = "";
        }
    }
    if(number != "")
    {
        res.push_back(std::stoi(number));
    }
    sort(res.begin(), res.end());
    for(const int& n:res)
    {
        cout<<n<<endl;
    }
    return 0;
}
