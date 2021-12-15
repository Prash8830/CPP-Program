#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main()
{
    fio;
    
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0; i<n; i++)cin>>arr[i];

    reverse(arr.begin(),arr.end());
    for(int i=0; i<n; i++)cout<<arr[i]<<" ";
    
    return 0;
}