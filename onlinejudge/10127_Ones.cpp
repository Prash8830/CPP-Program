//10127_Ones
#include <iostream>
using namespace std;

int main() {
    
    int n;
    while(cin>>n)
    {
        int cd=1;
        int i=1;
        while(i%n!=0)
        {
            i=(i*10+1)%n;
            cd++;
        }
        cout<<cd<<endl;
    }
    
	return 0;
}
/* Input
3
7
9901
 Output
3
6
12*/
