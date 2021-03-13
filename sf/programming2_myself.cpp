#include <iostream>
#include <vector>

//顺丰视觉算法工程师笔试

using namespace std;

int main()
{
    // getting data
    int n, q;
    int x=0;
    cin>>n>>q;
    int a_set[n], l[q], r[q];
    for(int i=0;i<n; i++)
    {
        cin>>a_set[i];
    }
    for(int i=0;i<q;i++)
    {
        cin>>l[i]>>r[i];
    }

    // enquire
    int max, maxIndex, min, minIndex, sum, avg;
    for(int i=0;i<q;i++)
    {
        int length = r[i]-l[i] +1;
        if(length < 3)
        {
            cout<<"NoScore"<<endl;
        } else{
            maxIndex = minIndex = l[i]-1;
            max = a_set[maxIndex];
            min = a_set[minIndex];
            sum = 0;
            for(int j=l[i]-1;j<r[i];j++)
            {
                if(a_set[j]>max)
                {
                    max=a_set[j];
                    maxIndex=j;
                }
                if(a_set[j]<min)
                {
                    min=a_set[j];
                    minIndex=j;
                }
                sum += a_set[j];
            }
            int sum_tmp;
            sum_tmp = sum-a_set[maxIndex]-a_set[minIndex];
            avg = sum_tmp/(length-2);
            cout<<avg<<endl;
        }
    }
    return 0;
}
