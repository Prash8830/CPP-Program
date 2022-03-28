#include <bits/stdc++.h>
using namespace std;

bool sieve(int n)
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    int sumd=0,sump=0;
    int k=n;
    while(k)
    {
        sumd+=k%10;
        k/=10;
    }
    for (int p = 2; p <= n; p++)
        if(n%p==0)
        if (prime[p])
        {
            int cnt=0;
            int no=n;
            while(no%p==0)
            {
                cnt++;
                no/=p;
            }
            int k=p;
            int temp=0;
            while(k)
            {
                temp+=k%10;
                k/=10;
            }
            sump +=temp*cnt;
        }
    return sumd==sump;    
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    n++;
	    while(sieve(n)==0)
	        n++;
	        
	   cout<<n<<"\n";     
	    
	}
	return 0;
}
