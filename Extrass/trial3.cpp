#include<bits/stdc++.h>
using namespace std;
 #include<numeric>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);

int main()
{
    fio;
    
    vector<int>m={54,12,54,87,54,123,687,54,123};
    vector<int>n(9);
    partial_sum(m.begin(), m.end(), n);
    for(auto i: n)cout<<i<<" ";
    return 0;
}