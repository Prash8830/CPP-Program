#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main()
{
    fio;
    
    int n,k;
    cin >> n >> k;
    vector<int>arr(n+1);
    stack<int>s;
    for(int i = 1; i <=n; i++)cin>>arr[i];
    long long m = 1000000007;
    long long f = 1;
    for(int i = n; i>=1; i--)
    {
        while(s.size()!=0 && arr[i]<=arr[s.top()])    
            s.pop();

        if(s.size()!=0 && arr[i]>arr[s.top()])  
            f = ( f * (s.top()-i+1) ) % m;

        s.push(i);    
    }
    cout<<f<<"\n";
    return 0;
}