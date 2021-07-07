#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int gcd(int a, int b)
{
    if(b%a==0)return a;
    return gcd(b,b%a);
}

int main()
{
    fio;
    
    cout<<gcd(16,24);
    
    return 0;
}