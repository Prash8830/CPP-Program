// 10188 - Automated Judge Script
#include <bits/stdc++.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define E 2.71828182845904523536
#define long long LL
using namespace std;
 
int main()
{
    int correctN, testN, counter=0;
    char Input[100000];
    while(gets(Input) != NULL)
    {
        counter++;
 
        correctN = atoi(Input);
        if (correctN == 0) return 0;
        string CO="", FCO="", TO="", FTO="";
 
        for (int i=0; i<correctN; i++)       {           gets(Input);            CO += Input;            if (i > 0) CO += '\n';
            for (int i=0; i<strlen(Input); i++)
                if (isdigit(Input[i])) FCO += Input[i];
 
        }
 
        bool AC=true, PE=false;
        gets(Input);
        testN = atoi(Input);
 
        for (int i=0; i<testN; i++)      {           gets(Input);                            TO += Input;            if (i > 0) TO += '\n';
            for (int i=0; i<strlen(Input); i++)
                if (isdigit(Input[i])) FTO += Input[i];
 
        }
 
        if (FTO != FCO) AC = false;
        if (CO != TO) PE = true;
 
            cout << "Run #" << counter << ": ";
            if (!AC) cout << "Wrong Answer";
            else if (AC && PE) cout << "Presentation Error";
            else cout << "Accepted";
 
            cout << "\n";
 
    }
    return 0;
}
// Input:
// 2
// The answer is: 10
// The answer is: 5
// 2
// The answer is: 10
// The answer is: 5
// 2
// The answer is: 10
// The answer is: 5
// 2
// The answer is: 10
// The answer is: 15
// 2
// The answer is: 10
// The answer is: 5
// 2
// The answer is: 10
// The answer is: 5
// 3
// Input Set #1: YES
// Input Set #2: NO
// Input Set #3: NO
// 3
// Input Set #0: YES
// Input Set #1: NO
// Input Set #2: NO
// 1
// 1 0 1 0
// 1
// 1010
// 1
// The judges are mean!
// 1
// The judges are good!
// 0

// Output:
// Run #1: Accepted
// Run #2: Wrong Answer
// Run #3: Presentation Error
// Run #4: Wrong Answer
// Run #5: Presentation Error
// Run #6: Presentation Error