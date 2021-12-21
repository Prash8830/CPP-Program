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
        bool f=0;
        if(s.length()%2!=0) cout<<"NO"<<"\n";
        else
        {
            for(int i=0; i<s.length()/2; i++)
            {
                if(s[i]!=s[i+(s.length()/2)])
                {
                    cout<<"NO"<<"\n";
                    f=1;
                    break;
                }
            }
            if(f==0) cout<<"YES"<<"\n";
        }
    }
    
    return 0;
}