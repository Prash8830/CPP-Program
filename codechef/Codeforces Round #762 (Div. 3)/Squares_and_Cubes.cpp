#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main()
{
    fio;
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int s = sqrt(n);
        int c  =cbrt(n);
        int a = s+c;
        int i=1;
        while (true)
        {
            if(pow(i,6)<=n)
            {
                a--;
                i++;
            }
            else 
            {
                break;
            }
        }
        cout << a <<"\n";
    }
    
    return 0;
}