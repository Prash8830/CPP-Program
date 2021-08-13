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
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0; i<n; i++)cin>>a[i];
        vector<int>b(n);
        for(int i=0; i<n; i++)cin>>b[i];
        pair<int,vector<int>>p;
        vector<int>check(n);
        for(int i=0; i<n; i++)check[i]=i;
        for(int i=0; i<n; i++)
        {
            p.first=INT_MAX;
            for(int j=0; j<check.size(); j++)
            {
                if((a[i]+b[(i+check[j])%n])%n<p.first)
                {
                    p.first=(a[i]+b[(i+check[j])%n])%n;
                    vector<int>m;
                    m.push_back(check[j]);
                    p.second=m;
                }
                else if((a[i]+b[(i+check[j])%n])%n==p.first)
                {
                    p.second.push_back(check[j]);
                }
            }
            if(p.second.size()==1)
            {
                for(int i=0; i<n; i++)
                {
                   cout<<(a[i]+b[(i+p.second[0])%n])%n<<" ";
                }
                break;
            }
            else
            {
                if(i==n-1)
                {
                    for(int i=0; i<n; i++)
                    {
                        cout<<(a[i]+b[(i+p.second[0])%n])%n<<" ";
                    }
                    break;
                }
                check=p.second;
            }

        }
        cout<<"\n";
    }
    
    return 0;
}