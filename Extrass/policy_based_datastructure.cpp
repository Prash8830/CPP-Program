//it uses oreders set which use red black tree
//it has two key options 
//order_of_key(k) - no of item strictly smaller than k
//find_by_order(k) - kth element in set(counting from 0)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
int main()
{
    fio;
    
    oset<int> s;
    s.insert(5);
    s.insert(4);
    s.insert(3);
    s.insert(6);

    cout<<*s.find_by_order(2)<<endl;
    cout<<s.order_of_key(6);
    
    return 0;
}