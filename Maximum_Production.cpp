#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main()
{
    fio;
    
    int t;
    cin>>t;
    while (t--)
    {
        int d,x,y,z;
        cin>>d>>x>>y>>z;
        cout<<max((7*x),((d*y)+((7-d)*z)))<<"\n";
    }
    
    return 0;
}