#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);

struct dim
{
    int h,w,d;
};

int main()
{
    fio;
    
    int n;
    cin >> n;
    vector<dim>arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i].h >> arr[i].w >> arr[i].d;
    
    
    return 0;
}