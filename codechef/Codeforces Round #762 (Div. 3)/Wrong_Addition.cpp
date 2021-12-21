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
        long long a,s;
        cin >> a >> s ;
        string x = to_string(a);
        string y = to_string(s);
        int j = y.size()-1;
        string b;
        bool f=0;
        for(int i=x.size()-1; i>=0; i--)
        {
            if(j<0)
            {
                cout<<-1<<"\n";
                f=1;
            }
            else if(int(x[i])<=int(y[j]))
            {
                b = to_string( int(y[j]) - int(x[i]) ) + b;
                j--;
            }
            else
            {   
                if(j==0 || y[j-1]!='1')
                {
                    cout<<-1<<"\n";
                    f=1;
                    break;
                }
                else
                {
                    b = to_string( (10+int(y[j])) - int(x[i]) ) + b;
                    j-=2;
                }
            }
        }
        bool k=0;
        if(f==0)
        {
            while(j>=0)
            {
                b = y[j] + b;
                j--;
            }
            for(int i=0; i<b.size(); i++)
            {
                if(b[i]!='0') k=1;
                if(k==1)cout<<b[i];
            }
            if(k==0)
            {
                cout<<0;
            }
            cout << "\n";
        }
    }
    
    return 0;
}