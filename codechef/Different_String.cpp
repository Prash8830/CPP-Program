#include <bits/stdc++.h>
using namespace std;

#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int main()
{
    fio;

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<string> arr(n);
        string ans;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i][i] == '1')
                ans.append("0");
            else
                ans.append("1");
        }
        cout << ans << "\n";
    }

    return 0;
}