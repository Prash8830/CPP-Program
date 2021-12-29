#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);

bool check(char a)
{
    if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') return true;
    return false;
}

int main()
{
    fio;
    
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s,p;
        cin >> s >> p;
        int a=0,v=0,c=0;
        vector<int>arr(256);
        for(int i=0; i<n; i++)
        {
            if(s[i]!='?' && p[i]!='?') //both are not ?
            {
                if(s[i]!=p[i])
                {
                    if(check(s[i])==check(p[i]))//same type 
                        a+=2;
                    else //different type
                        a++;  
                }  
            }
            else if((s[i]!='?' && p[i]=='?')||(s[i]=='?' && p[i]!='?'))//alternate ?
            {
                if(s[i]!='?')
                {
                    if(check(s[i])) v++;
                    else c++;
                    arr[s[i]]+=1;
                }
                else
                {
                    if(check(p[i])) v++;
                    else c++;
                    arr[p[i]]+=1;
                }
            }
        }
        int vmax=0,cmax=0;
        for(int i=97; i<=122; i++)
        {
            if(check(char(i))){
                if(arr[i]>vmax) 
                    vmax=arr[i];
            }        
            else {
                if(arr[i]>cmax) 
                    cmax=arr[i];
            }        
        }
        if(v==0 || c==0)
            a+=min((max(v,c)-max(vmax,cmax))*2,max(v,c));
        else if((v>=c)&&(vmax<=cmax))
            a+=v+(c-cmax)*2;
        else if((c>=v)&&(cmax<=vmax))
            a+=c+(v-vmax)*2;
        else
            a+=min(v+(c-cmax)*2,c+(v-vmax)*2);   
        cout<<a<<"\n";       
    }
    
    return 0;
}