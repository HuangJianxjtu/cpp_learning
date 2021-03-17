#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t=0;
    cin>>t;
    vector<vector<vector<int>>> dataSets;
    for(int kk=0;kk<t;kk++){
        vector<vector<int>> single_dataSet;
        vector<int> expects, values;

        int m=0, n=0;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            int num_tmp = 0;
            cin>>num_tmp;
            expects.push_back(num_tmp);
        }
        for(int i=0;i<m;i++){
            int num_tmp = 0;
            cin>>num_tmp;
            values.push_back(num_tmp);
        }
        single_dataSet.push_back(expects);
        single_dataSet.push_back(values);

        dataSets.push_back(single_dataSet);
    }

    for(int kk=0;kk<t;kk++){
        int n, m;
        vector<int> results;

        n = dataSets[kk][0].size();
        m = dataSets[kk][1].size();
        for(int i=0;i<n;i++){
            int counting = 0;
            for(int j=0;j<m;j++){
                if(dataSets[kk][0][i] <= dataSets[kk][1][j]){
                    counting += 1;
                }
            }
            results.push_back(counting);
        }

        for(int i=0;i<n;i++){
            cout<<results[i];
            if(i<n-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }



    return 0;
}