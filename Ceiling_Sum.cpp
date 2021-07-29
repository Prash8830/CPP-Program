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
        long long a,b;
        cin>>a>>b;
        
        long long sum = INT_MIN;
        for(long long i=min(a,b); i<=max(a,b); i++)
        {
            long long z = ceil(double(b-i)/2)+ceil(double(i-a)/2);
            sum = max(sum, z);
        }
        long long i;
        if(a%2==b%2)
        {
            i = min(a,b)+1;
        }
        else
        {
            i = min(a,b);
        }
        long long z = ceil(double(b-i)/2)+ceil(double(i-a)/2);     
        cout<<sum<<" "<<z<<"\n";
    }
    
    return 0;
}