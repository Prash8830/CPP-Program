#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
class solution
{
    public:
    int maxSubarrayXOR(int n, int arr[])
    {
        
    }

};

int main()
{
    fio;
    
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)cin>>arr[i];
    solution obj;
    cout<<obj.maxSubarrayXOR(n,arr);
    
    return 0;
}