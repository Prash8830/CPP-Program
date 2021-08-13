#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main()
{
    fio;
    
    int t;
    cin >> t;
    while(t--)
    {
        long long n,p,k;
        cin>>n>>p>>k;
        cout<<1+(p%k)*(n/k)+(p/k)+min(p%k,n%k)<<"\n";
    }
    
    return 0;
}