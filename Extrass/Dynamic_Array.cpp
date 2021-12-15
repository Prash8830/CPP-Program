#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main()
{
    fio;
    
    long long n,q;
    cin>>n>>q;

    long long ls=0;
    vector<vector<long long>>arr(n);

    long long t,x,y; 
    for(int i=0; i<q; i++)
    {
        cin>>t>>x>>y;

        if(t==1)
        {
            arr[(x^ls)%n].push_back(y);     
        }
        else
        {
            ls=arr[(x^ls)%n][y%(arr[(x^ls)%n].size())];
            cout<<ls<<"\n";
        }
    }   

    return 0;
}