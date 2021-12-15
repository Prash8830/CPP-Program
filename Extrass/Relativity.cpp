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
        int g,c;
        cin>>g>>c;
        cout<<(pow(c,2)/(2*g))<<"\n";
    }
    
    return 0;
}