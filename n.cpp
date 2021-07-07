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

        /*vector<int>arr(n);  //input array
        for(int i=0; i<n; i++)cin>>arr[i];*/

        if (n == 1) // corner case
        {
            cout << 1 << "\n";
        }

        bool set = false; //variable declaration
        int cg, ag, tg, an, m = INT_MIN;
        long long res;

        int a, b; //first two numbers
        cin >> a >> b;

        cg = gcd(a, b); //pre-computation for first two num
        res = (a / cg) + (b / cg);
        m = max(a, b);
        /*cout << "cg=" << cg << endl;
        cout << "res=" << res << endl;*/
        for (int i = 3; i <= n; i++)
        {
            cin >> a;
            tg = gcd(cg, a);
            m = max(m, a);

            if (tg < cg)
            {
                if (set) //alter is already used
                {
                    if (tg > ag) //gcd is less but not as much than alteg gcd
                    {
                        res = ((res - 1) * (cg / tg)) + 1;
                        res += a / tg;
                        cg = tg;
                    }
                    else if (tg < ag) //gcd is lesser so update alter
                    {
                        res = ((res - 1) * (cg / ag)) + 1;
                        res += an / ag;
                        cg = ag;
                        ag = tg;
                        an = a;
                    }
                    else //gcd is less but = alter gcd
                    {
                        set = false;
                        res--;
                        res = res * (cg / tg);
                        res += (an / tg) + (a / tg);
                        cg = tg;
                    }
                }
                else //first time alter
                {
                    set = true;
                    ag = tg;
                    an = a;
                    res++;
                }
            }
            else //when gcd has no change
            {
                res += a / cg;
            }
            /*cout << "cg=" << cg << endl;
            cout << "res=" << res << endl;*/
        }

        if (!set) //use of alter power
        {
            res -= m / cg;
            res++;
        }

        cout << res << "\n";
    }

    return 0;
}