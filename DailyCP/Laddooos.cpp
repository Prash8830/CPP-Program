#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main()
{
    fio;
    
    int t;
    cin >> t;
    while (t--)
    {
        int n,q;
        cin >> n >> q;
        pair<int,int>p(-1,-1);
        vector<pair<int,int>>arr(n+1,p);
        stack<int>s;
        for (int i = 1; i <= n; i++) 
        {
            int v;
            cin >> v;
            if(v!=0)
            {
                arr[v].first = i;
                arr[v].second = n+1;
                s.push(v);
            }
            else if(v==0 && s.size()!=0)
            {
                arr[s.top()].second = i;
                s.pop();
            }
        }
        for(int i=0; i<q; i++)
        {
            int a,b;
            cin >> a>>b;
            if((arr[a].first>arr[b].first && arr[a].first<arr[b].second)||(arr[b].first>arr[a].first && arr[b].first<arr[a].second))
                cout<<"YES"<<"\n";
            else
                cout<<"NO"<<"\n";    
        }
    }
    
    return 0;
}