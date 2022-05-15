// 10158 - War : Solution by Prashant Patil

#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int 
#define pb push_back 
#define endl "\n" 

int par[10000];
int rank1[10000];
int enemy[10000];

int findPar(int x)
{
    if(x==par[x])
        return x;
    return par[x] = findPar(par[x]);
}

int unionSet(int x, int y)
{
    x = findPar(x);
    y = findPar(y);
    if(rank1[x]<rank1[y])
    {
        par[x] = y;
        return y;
    }
    else if(rank1[y]<rank1[x])
    {
        par[y] = x;
        return x;
    }
    else
    {
        par[y] = x;
        rank1[x]++;
        return x;
    }
}


void setFriends(int x, int y)
{
    x = findPar(x);
    y = findPar(y);

    if(enemy[x]==y)
    {
        cout<<-1<<endl;
        return;
    }
    if(x==y)
        return;

    int fpar = unionSet(x,y); 

    int epar = max(enemy[x],enemy[y]);
    if(enemy[x]!=-1 && enemy[y]!=-1)       
        epar = unionSet(enemy[x],enemy[y]); 

    if(epar!=-1) 
    {
        enemy[epar] = fpar;
        enemy[fpar] = epar;
    }   
}

void setEnemies(int x, int y)
{
    x = findPar(x);
    y = findPar(y);

    if(x==y)
    {
        cout<<-1<<endl;
        return;
    }
    if(enemy[x]==enemy[y] && enemy[x]!=-1)
        return;

    int fpar = x;    
    if(enemy[y]!=-1)
        fpar = unionSet(x,enemy[y]);

    int epar = y;
    if(enemy[x]!=-1) 
        epar = unionSet(enemy[x],y); 

    enemy[epar] = fpar;
    enemy[fpar] = epar;
}

void areFriends(int x, int y)
{
    x = findPar(x);
    y = findPar(y);
    if(x==y)
        cout<<1<<endl;
    else
        cout<<0<<endl;    
}

void areEnemies(int x, int y)
{
    x = findPar(x);
    y = findPar(y);
    if(enemy[x]==y)
        cout<<1<<endl;
    else
        cout<<0<<endl;    
}

void solve()
{

    int n;
    cin>>n;

    for(int i=0; i<n; ++i)
    {
        par[i] = i;  
        rank1[i] = 0; 
        enemy[i] = -1;  
    }

    int c,x,y;
    while(cin>>c>>x>>y)
    {
        if(c==0 && x==0 && y==0) 
            break;
        if(c==1)
            setFriends(x,y);
        else if(c==2)
            setEnemies(x,y);
        else if(c==3)
            areFriends(x,y);
        else
            areEnemies(x,y);                
    }

}

int main()
{
    fio;
    
    solve();
    
    return 0;
}

// Input:
// 10
// 1 0 1
// 1 1 2
// 2 0 5
// 3 0 2
// 3 8 9
// 4 1 5
// 4 1 2
// 4 8 9
// 1 8 9
// 1 5 2
// 3 5 2
// 0 0 0

// Output:
// 1
// 0
// 1
// 0
// 0
// -1
// 0
