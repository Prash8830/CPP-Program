#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main()
{
    fio;
    
    long long t;
    cin>>t;
    while(t--)
    {
        long long n,m,p;
        vector<long long>a(n+1);
        for(long long i=1;i<=n;i++)cin>>a[i];
        vector<long long>b(m+1);
        for(long long j=1;j<=m;j++)cin>>b[j];
        long long goodPairs=0;
        for(long long i = 1; i<=n; i++)
        {
            for(long long j =1; j<=m; j++)
            {
                if(a[i]^b[j]<p && ((a[i]*(a[i]^b[j]))-1))
                {
                    goodPairs++;
                }
            }
        }
        cout << goodPairs << "\n";
    }
    
    return 0;
}