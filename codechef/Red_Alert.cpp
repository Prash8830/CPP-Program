#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main()
{
    fio;
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,d,h;
        cin>>n>>d>>h;
        vector<int>days(n);
        for(int i=0; i<n; i++)cin>>days[i];
        int sum=0;
        bool f=0;
        for(int i=0; i<n; i++)
        {
            if(days[i]!=0) sum+=days[i];
            else sum = max(sum-d,0);
            if(sum>h)
            {
                cout<<"YES"<<"\n";
                f=1;
                break;
            }
        }
        if(f==0)cout<<"NO"<<"\n";
    }
    
    return 0;
}