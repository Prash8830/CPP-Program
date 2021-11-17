#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);

long long countC(int n)
{
    long long c = 1;
    while(n!=1)
    {
        if(n%2==1) n=3*n+1;
        else n=n/2;
        c++;
    }
    return c;
}
 
int main()
{
    fio;
    
    int i,j;
    while(cin >> i >> j)
    {
        long long c=0;
        for(int k=min(i,j); k<=max(i,j); k++) c = max(c,countC(k));
        cout << i<<" " << j<<" " << c<<endl;
    }
    
    return 0;
}