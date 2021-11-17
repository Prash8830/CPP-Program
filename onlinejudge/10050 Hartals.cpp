#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n,p;
	    cin>>n>>p;
	    vector<int>freq(p);
	    for(int i=0; i<p; i++)cin>>freq[i];
	    vector<vector<bool>>table(p,vector<bool>(n));
	    for(int i=0; i<p; i++)
	    {
	        for(int j=0; j<n; j++)
	        {
	            if((j+1)%freq[i]==0)table[i][j]=1;
	        }
	    }
	    int w=0;
	    for(int j=0; j<n; j++)
	    {
	        if((j+1)%7!=6 && (j+1)%7!=0)
	        {
	            for(int i=0; i<p; i++)
	            {
	                if(table[i][j]==1)
	                {
	                    w++;
	                    break;
	                }
	            }
	                
	        }
	    }
	    cout<<w<<"\n";
	    
	}

	
	return 0;
}
