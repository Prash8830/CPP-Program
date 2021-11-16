#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	while(cin>>n)
	{
	    vector<int>arr(n);
	    vector<bool>diff(n,0);
	    for(int i=0; i<n; i++)cin>>arr[i];
	    for(int i=1; i<n; i++)
	    {
	        diff[abs(arr[i]-arr[i-1])]=1;
	    }
	    bool j=1;
	    for(int i=1; i<n; i++)
	    {
	        if(diff[i]==0)
	        {
	            j=0;
	            break;
	        }
	    }
	    if(j==1)
	    {
	        cout<<"Jolly"<<"\n";
	    }
	    else
	    {
	        cout<<"Not jolly"<<"\n";
	    }
	}

	
	return 0;
}
