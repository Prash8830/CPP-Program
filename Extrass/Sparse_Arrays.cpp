#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main()
{
    fio;
    
    int n,q;
    cin>>n;
    unordered_map<string,int>map;
    string s;
    for(int i=0; i<n; i++) 
    {
        cin>>s;
        map[s]++;
    }
    cin>>q;
    for(int i=0; i<q; i++) 
    {
        cin>>s;
        cout<<map[s]<<"\n";
    }
    
    return 0;
}