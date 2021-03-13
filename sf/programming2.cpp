#include <iostream>

//顺丰视觉算法工程师笔试
//正确率0%

using namespace std;

int main()
{
    int n=0, q=0;
    // int n=0, q=0;
    int* scores = new int[n];
    cin>>n>>q;

    for(int i=0;i<n;i++)
    {
        cin>>scores[i];
    }
    int* al = new int[q];
    int* ar = new int[q];
    for(int i=0;i<q;i++)
    {
        cin>>al[i]>>ar[i];
    }
    for(int i=0; i<n;i++)
    {
        int* a1 = new int[q];
        int* ar = new int[q];
    }
    for(int i=0;i<q;i++)
    {
        int num = 0, min =100, max=0, minIndex =-1, maxIndex = -1, avg = 0;
        al[i]--;
        ar[i]--;
        num = ar[i]-al[i]+1;
        if(num<3)
        {
            cout<<"NoScore"<<endl;
        }
        else
        {
            for(int idx = al[i];idx<ar[i];idx++)
            {
                if(scores[idx]<min)
                {
                    min = scores[idx];
                    minIndex = idx;
                }
                if(scores[idx]>max)
                {
                    max = scores[idx];
                    maxIndex = idx;
                }
            }
            int* scored = new int[num];
            for(int idx=al[i];idx < ar[i];idx ++)
            {
                if(idx == minIndex||idx==maxIndex)
                {
                    continue;
                } else
                {
                    avg += scores[idx];
                }
            }
            cout << avg/(num-2)<<endl;
        }
    }

    return 0;
}