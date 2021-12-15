#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int glass(vector<vector<int>>arr,int i,int j)
{
    int ans=0;
    for(int k=0; k<3; k++)ans+=arr[i][j+k]+arr[i+2][j+k];
    ans+=arr[i+1][j+1];
    return ans;
}

int main()
{
    fio;
    
    vector<vector<int>>arr(6,vector<int>(6));
    for(int i=0; i<6; i++)for(int j=0; j<6; j++)cin>>arr[i][j];
    int res=INT_MIN;

    for(int i=0; i<4; i++)for(int j=0; j<4; j++)res=max(res,glass(arr,i,j));
    cout<<res<<"\n";
    
    return 0;
}