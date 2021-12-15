#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main()
{
    fio;
    
    int n,m,a,b;
    cin>>n>>m;
    long long k;
    vector<long long>arr(n);
    for(int i=0; i<m; i++)
    {
        cin>>a>>b>>k;
        arr[a-1]+=k;
        if(b<n) arr[b]-=k;
    }
    for(int i=1; i<n; i++)arr[i]+=arr[i-1];
    k=0;
    for(int i=0; i<n; i++)k=max(k,arr[i]);
    cout<<k<<"\n";
    return 0;
}