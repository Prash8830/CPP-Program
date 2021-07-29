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
        long long n,d;
        cin>>n>>d;
        vector<long long>price(n);
        vector<long long>sweetness(n);
        for(int i=0; i<n; i++)cin>>price[i];
        for(int i=0; i<n; i++)cin>>sweetness[i];
        map<long long, long long>m;
        long long sweet = 0;
        for(int i=0; i<n; i++)
        {
            if(price[i]<=d)
            {
                if((*m.upper_bound(price[i])).second==0)
                {
                    if(m.count(d-price[i])==0)
                    {
                        sweet = max(sweet, sweetness[i]);
                        m[d-price[i]] = sweetness[i];
                    }
                    else
                    {
                        m[d-price[i]] = max(m[d-price[i]],sweetness[i]);
                        sweet = max(sweet,m[d-price[i]]);
                    }
                }
                else
                {
                    sweet = max(sweet, sweetness[i]+(*m.upper_bound(price[i])).second);
                    m[d-price[i]] = sweetness[i];
                }
            }
        }
        cout<<sweet<<"\n";

    }
    
    return 0;
}