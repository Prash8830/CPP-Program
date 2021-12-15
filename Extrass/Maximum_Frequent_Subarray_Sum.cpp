#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
    
        long long score=INT_MIN,mk=INT_MIN;
        unordered_map<string,int>m;
        
        for(int i=0; i<n; i++)
        { 
            mk=max(mk,(long long)arr[i]);
            if(arr[i]<=0) continue;
            
            string s="";
            long long sum=0;

            for(int j=i; j<n; j++)
            {
                s=s+" "+to_string(arr[j]);
                sum+=arr[j];
                if(sum<=0)break;
                m[s]++;
                score=max(score,(sum*m[s]));
            }
        }
        score=max(score,mk);
        cout<<score<<"\n";
    }
    
	return 0;
}
