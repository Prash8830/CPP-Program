//10035 Primary Arithmetic
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string a,b;
    while(1)
    {
        cin>>a>>b;
        if(a[0]=='0' && b[0]=='0') break;
        while(a.size()<b.size())a="0"+a;
        while(b.size()<a.size())b="0"+b;
        int no = 0;
        bool c=0;
        for(int i=a.size()-1; i>=0; i--)
        {
            if(int(a[i])- 48 +int(b[i])- 48+((c==1)?1:0)>9)
            {
                no++;
                c=1;
            }
            else c=0;
        }
        if(no==0) cout<<"No";
        else cout<<no;
        if(no==0 || no==1) cout<<" carry operation."<<"\n";
        else cout<<" carry operations."<<"\n";
    }
    
    
	return 0;
}
/* Input:
123 456
555 555
123 594
0 0
 Output:
No carry operation.
3 carry operations.
1 carry operation.*/
