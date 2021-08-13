#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);

int factors(int n)
{
    int count = 0;
    float sq=sqrt(n);
    for(int i=2; i<sq; i++)
    {
        if(n%i==0) count++;
    }
    count*=2;
    int s=sq;
    if(s*s==n) count++;
    return count;
}
  
int main()
{
    fio;
    

    //initial computation    
    vector<long long>res(pow(10,5)+1);
    res[2]=1;
    int c,p=1;
    for(int i=3; i<=pow(10,5); i++)
    {
        c=factors(i);
        c++;
        res[i]=c+p+res[i-1];
        p=c;
        for(int j=2; j<((float)i)/2; j++)
        {
            if((i-j)%j==0) res[i]+=1;
        }
    }
    
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        cout<<res[n]<<"\n";
    }
    
    return 0;
}
