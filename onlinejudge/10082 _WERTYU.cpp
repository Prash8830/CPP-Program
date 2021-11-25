#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s1="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    
    string s2;
    int n;
    
    while(getline(cin, s2))
    {
        string ans="";
        for(int i=0;i<s2.size();i++)
        {        
            if(s2[i]!='Q' && s2[i]!='A' && s2[i]!='Z')
            {
                n=s1.find(s2[i]);
                if(n!=-1)
                {
                    ans.append(s1,n-1,1); //append 1 character
                }else ans.append(s2,i,1);//append space 
            }else ans.append(s2,i,1);//append space
        }
        cout<<ans<<endl;
    }
    return 0;
}
//Output:
//I AM FINE TODAY.