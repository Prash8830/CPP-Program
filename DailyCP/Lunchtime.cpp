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
        int n;
        cin >> n;  
        vector<int>arr(n+1);
        vector<int>ans(n+1);
        stack<pair<int, int>>s;

        for (int i=1; i<=n; i++) cin >> arr[i];

        for (int i=n; i>=1; i--)
        {
            while(s.size() != 0 && s.top().first<arr[i]) 
                s.pop();
            if(s.size() != 0 && s.top().first==arr[i])
            {
                ans[i] = s.top().second;
                s.top().second++;
            }   
            else
            {
                pair<int,int>p(arr[i],1);
                s.push(p);
            } 
        }
        while(s.size() != 0)
            s.pop();
        for (int i=1; i<=n; i++)
        {
            while(s.size() != 0 && s.top().first<arr[i]) 
                s.pop();
            if(s.size() != 0 && s.top().first==arr[i])
            {
                ans[i] += s.top().second;
                s.top().second++;
            }   
            else
            {
                pair<int,int>p(arr[i],1);
                s.push(p);
            } 
        }
        for (int i=1; i<=n; i++)cout<<ans[i]<<" ";
        cout << "\n";
    }
    
    return 0;
}