// 850 - Crypt Kicker II
#include <bits/stdc++.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define E 2.71828182845904523536
#define long long LL
using namespace std;
 
char mappings[128];
vector<string> alphabetTokens;
bool mapLetters(vector<string> encrypted)
{
    char Rmappings[128];
 
    for (int i=0; i<128; i++)
        mappings[i] = Rmappings[i] = 0;
 
    for (int i=0; i<alphabetTokens.size(); i++)
    {
        for (int j=0; j<alphabetTokens[i].length(); j++)
        {
            if ( (mappings[encrypted[i][j]] == 0 && Rmappings[alphabetTokens[i][j]] == 0)
                || (mappings[encrypted[i][j]] == alphabetTokens[i][j] ))
                mappings[encrypted[i][j]] = alphabetTokens[i][j] ;
            else return false;
        }
    }
 
    return true;
}
int main()
{
    int N;
 
    cin >> N;
    cin.get();
    cin.get();
    string alphabet = "the quick brown fox jumps over the lazy dog";
    stringstream s(alphabet);
 
    while(!s.eof()) 
    {
        string T;
        s >> T;
        alphabetTokens.push_back(T);
    }
 
    for (int i=0; i<N; i++)
    {
        if (i > 0) cin.get();
        vector< vector<string> > InputTokens;
        while(1)
        {
            if (cin.peek() == '\n' || cin.eof()) break;
            InputTokens.push_back(*(new vector<string>));
            string T;
            getline(cin,T);
 
            stringstream s(T);
 
            while(!s.eof())
            {
                s >> T;
                InputTokens[InputTokens.size()-1].push_back(T);
            }
        }
 
        bool Possible = false;
        for (int i=0; i<InputTokens.size(); i++)
        {
             
 
            if(InputTokens[i].size() == alphabetTokens.size())
                {
                    Possible = true;
                    for (int j=0; j<InputTokens[i].size(); j++)
                    {
                        if (InputTokens[i][j].length() != alphabetTokens[j].length())
                            Possible = false;
                    }
 
                    if (Possible)
                        {
                            if (!mapLetters(InputTokens[i])) Possible = false;
                            else break;
                        }
                     
                }
        }
 
     
        if (Possible)
            for (int j=0; j<InputTokens.size(); j++)
            {
                for (int k=0; k<InputTokens[j].size(); k++)
                {
                    for (int l=0; l<InputTokens[j][k].length(); l++)
                        cout << mappings[InputTokens[j][k][l]];
                    if (k != InputTokens[j].size() - 1) cout << " ";
                }
                if (j != InputTokens.size()-1) cout << endl;
            }
        else cout << "No solution.";
 
        cout << endl;
        if (i != N-1) cout << endl;
 
         
    }
 
    return 0;
}
//Input:
// 1
// vtz ud xnm xugm itr pyy jttk gmv xt otgm xt xnm puk ti xnm fprxq
// xnm ceuob lrtzv ita hegfd tsmr xnm ypwq ktj
// frtjrpgguvj otvxmdxd prm iev prmvx xnmq

// Output:
// now is the time for all good men to come to the aid of the party
// the quick brown fox jumps over the lazy dog
// programming contests are fun arent they