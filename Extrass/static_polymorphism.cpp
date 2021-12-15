#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
//same functions with differnt no of overloads is called as staic polymorphism

void add(int a, int b)
{
    cout<<a+b;
}

void add(int a, int b, int c, int d)
{
    cout<<a+b+c+d;
}

void add(int a, int b, int c)
{
    cout<<a+b+c;
}

int main()
{
    fio;
    
    add(10,45,36);
    
    return 0;
}