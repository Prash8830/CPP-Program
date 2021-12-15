#include <bits/stdc++.h>
using namespace std;

#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int gcd(int a, int b) //greatest common divisior
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    fio;

    int t;
    cin >> t;
    while (t--)
    {
        int n; //array size
        cin >> n;
        
        vector<long long>arr(n);  //input array
        for(int i=0; i<n; i++)cin>>arr[i];
        sort(arr.begin(),arr.end());

        if (n == 1) // corner case
        {
            cout <<1<<"\n";
        }

        bool set = false; //variable declaration
        int cg=arr[n-1], ag, tg, og=arr[n-1];
        long long res=0,an;

        /*cg = gcd(arr[0],arr[1]); //pre-computation for first two num
        res = (arr[0] / cg) + (arr[1] / cg);*/
        /*cout << "cg=" << cg << endl;
        cout << "res=" << res << endl;*/
        for (int i = 0; i < n; i++)
        {
            tg = gcd(cg, arr[i]);
            og =gcd (og,arr[i]);
            if (tg < cg)
            {
                if (set) //alter is already used
                {
                    ag = gcd(cg,ag);  //update ag gcd by gcd with ag
                    if (tg > ag) //gcd is less but not as much than alter gcd
                    {
                        res = ((res - 1) * (cg / tg)) + 1;
                        res += arr[i] / tg;
                        cg = tg;
                    }
                    else if (tg < ag) //gcd is lesser so update alter
                    {
                        res = ((res - 1) * (cg / ag)) + 1;
                        res += an / ag;
                        cg = ag;
                        ag = tg;
                        an = arr[i];
                    }
                    else //gcd is less but = alter gcd
                    {
                        set = false;
                        res--;
                        res = res * (cg / tg);
                        res += (an/tg)+(arr[i]/tg);
                        cg = tg;
                    }
                }
                else //first time alter
                {
                    set = true;
                    ag = tg;
                    an = arr[i];
                    res++;
                }
            }
            else //when gcd has no change
            {
                res += arr[i] / cg;
            }
            /*cout << "cg=" << cg << endl;
            cout << "res=" << res << endl;*/
        }

        if (!set) //use of alter power
        {
            res -= arr[n-1] / cg;
            res++;
        }
        
        cout << res << "\n";
    }

    return 0;
}   