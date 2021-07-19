#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
bool vperp(pair<long,long> a, pair<long,long> b)
{
    return ((a.first/a.second)>=(b.first/b.second));
}

int main()
{
    fio;
    
    int t;
    cin>>t;

    while(t--)
    {
        int n,m;        //n - total no of apples
        cin>>n>>m;     //m - maxprice

        vector<pair<long,long>>apples(n); //first = vitamins & second = price

        for(int i=0; i<n; i++)  cin>>apples[i].first>>apples[i].second;

        sort(apples.begin(), apples.end(), vperp);

        vector<bool>mark(n);

        long vitamins = 0;
        for(int i=0; i<n; i++)
        {
            if(apples[i].second<=m)
            {
                vitamins += apples[i].first;  
                m -= apples[i].second;
                mark[i] = true;
            }             
            if(m==0) break;
        }
        //using power of spell 
        long mprice = 0;
        int i=0;
        while(mark[i])
        {
            mprice = max(mprice,apples[i].second);
            i++;
        }
        mprice += m; //add prev rem money
        if(apples[i].second>=mprice)
        {
            vitamins += apples[i].first;
            mark[i] = true;
        }
        else
        {
            vitamins += apples[i].first;
            mprice -= apples[i].second;
            mark[i] = true;
            //can we get any apples in remaing value of mprice 
            for(; i<n; i++)
            {
                if(mark[i]==false && apples[i].second<=mprice)
                {
                    vitamins += apples[i].first;
                    mprice -= apples[i].second;
                    mark[i] = true;
                }
                if(mprice=0) break;
            }
        }
        
        cout<<vitamins<< "\n";

    }
    
    return 0;
} 