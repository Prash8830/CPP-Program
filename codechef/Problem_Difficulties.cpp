#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main()
{
    fio;
    
    int t;
    cin>>t;
    while(t--)
    {
        int a1,a2,a3,a4;
        cin>>a1>>a2>>a3>>a4;
        unordered_map<int,int>m;
        int count = 2;
        m[a1]++;
        m[a2]++;
        m[a3]++;
        if(m[a3]==3)count--;
        m[a4]++;
        if(m[a4]==4)count--;
        if(m[a4]==3)count--;
        cout<<count<<"\n";
    }
    
    return 0;
}