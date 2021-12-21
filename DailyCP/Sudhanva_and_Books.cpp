#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main()
{
    fio;
    
    int t;
    cin>>t;
    stack<int>s;
    int a,b;
    while(t--)
    {
        cin>>a;
        if(a==1)
        {
            cin >>b;
            s.push(b);
        }
        else 
        {
            if(s.size()==0) cout<<"kuchbhi?"<<endl;
            else {
                a = s.top();
                s.pop();
                cout<<a<<endl;
            }
        }
    }
    
    return 0;
}