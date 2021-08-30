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
        vector<int> arr(n);
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            map[arr[i]]++;
        }
        int count = 0;
        for (auto i : map)
            count = max(count, i.second);
        cout << min(n - 2, n - count) << "\n";
    }

    return 0;
}