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
        string s;
        cin >> s;
        int q;
        cin >> q;
        vector<int> arr(q);
        vector<int> ans(s.size());
        for(int i=0; i<q; i++) cin>>arr[i];
        stack<int>c;
        for(int i=s.size()-1; i>=0; i--)
        {
            if(c.size() == 0 && s[i]=='(')
                ans[i]=-1;
            else if(c.size() != 0 && s[i]=='(')
            {
                ans[i]=c.top();
                c.pop();
            }    
            else
            {
                ans[i] = (i==s.size()-1)?-1:ans[i+1];
                c.push(i);
            }
        }
        for(int i = 0; i<q; i++)cout << ans[arr[i]-1]+((ans[arr[i]-1]==-1)?0:1) <<"\n";
    }
    
    return 0;
}