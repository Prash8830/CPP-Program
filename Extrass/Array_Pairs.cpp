#include <bits/stdc++.h>
using namespace std;

#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int main()
{
    fio;

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long long pairs = 0;
    int m;
    for (int i = 0; i < n - 1; i++)
    {
        m = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            m = max(m, arr[j]);
            if (arr[i] * arr[j] <= m)
                pairs++;
        }
    }
    cout << pairs;
    return 0;
}