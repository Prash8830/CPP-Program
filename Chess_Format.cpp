#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main()
{
    fio;
    
    long t;
    cin>>t;

    while(t--)
    {
        int a,b;
        cin>>a>>b;

        a = a+b;

        if(a<3)cout<<1<<"\n";
        else if(a>=3 && a<=10)cout<<2<<"\n";
        else if(a>=11 && a<=60)cout<<3<<"\n";
        else cout<<4<<"\n";

    }
    
    return 0;
}
