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
        long long e,k;
        cin>>e>>k;
        long count=1;
        while(e/k!=0)
        {
            e=floor(e/k);
            count++;
        }
        cout<<count<<"\n";
    }
    
    return 0;
}