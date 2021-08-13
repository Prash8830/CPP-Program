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
        int n;
        cin>>n;
        vector<int>arr(n);
        unordered_map<int,int>m;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            m[arr[i]]++;
        }
        long count=0;
        for(int i=0; i<n; i++)
        {
            count+=n-m[arr[i]];
        }
        cout<<count<<"\n";
    }
    
    return 0;
}