#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);

class player
{
    public:
    static int count;
    player()
    {
        count++;
    }
    ~player()
    {
        count--;
    }

};
//define staic data member
int player::count = 0;
int main()
{
    fio;
    
    player p1;
    cout<<player::count<<endl;

    player p2;
    cout<<player::count<<endl;

    delete &p1;
    cout<<player::count<<endl;
    
    return 0; 
}
