#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
struct block
{
    int value;
    int range=0;
    long long sum=0;
};

int main()
{
    fio;
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        long long s;
        cin>>n>>k>>s;
        vector<long long>seg(n);
        for(int i=0; i<n; i++)cin>>seg[i];
        deque<block>sub;
        int size = 0, maxs = 0;
        // for i == 0
        block a;
        a.value=seg[0];
        a.range=1;
        a.sum=seg[0];
        sub.push_front(a);
        for(int i=1; i<n; i++)
        {
            if(sub.back().sum+seg[i]<=s) //we can add in last block
            {
                block a;
                a.value=seg[i];
                a.range=sub.back().range;
                a.sum=sub.back().sum+seg[i];
                sub.push_front(a);
                size++;
            }
            else //we can't add in last block 
            {

                //we will create a new block if it does not exceed limit k
                if(sub.back().range<k)
                {

                }
                //we can't add new block so we start removing last elements
                else
                {

                }
            }
            maxs = max(maxs,size);
        }
    }
    
    return 0;
}