#include <bits/stdc++.h>
using namespace std;

vector<string> divide(string s)
{
    vector<string> a;
    string k;
    for (int i = 0; i < s.size(); i++)
    {
        if (!isspace(s[i]))
            k = k + s[i];
        else
        {
            a.push_back(k);
            k = "";
        }
    }
    if (k.size() != 0)
        a.push_back(k);
    return a;
}

int main()
{

    string command, c;
    vector<vector<string>> curr;
    while (1)
    {
        getline(cin, command);
        vector<string> ans;
        ans = divide(command);

        if (ans[0] == "I")
        {
            int m, n;
            m = stoi(ans[1]);
            n = stoi(ans[2]);
            vector<vector<string>> cur(n, vector<string>(m, "O"));
            curr = cur;
        }
        else if (ans[0] == "C")
        {
            for (int i = 0; i < curr.size(); i++)
            {
                for (int j = 0; j < curr[0].size(); j++)
                {
                    curr[i][j] = "O";
                }
            }
        }
        else if (ans[0] == "L")
        {
            int x, y;
            x = stoi(ans[1]);
            y = stoi(ans[2]);
            c = ans[3];
            curr[y - 1][x - 1] = c; //because of 0 based indexing
        }
        else if (ans[0] == "V")
        {
            int x, y1, y2;
            x = stoi(ans[1]);
            y1 = stoi(ans[2]);
            y2 = stoi(ans[3]);
            c = ans[4];
            for (int i = y1 - 1; i <= y2 - 1; i++)
                curr[i][x - 1] = c;
        }
        else if (ans[0] == "H")
        {
            int x1, x2, y;
            x1 = stoi(ans[1]);
            x2 = stoi(ans[2]);
            y = stoi(ans[3]);
            c = ans[4];
            for (int i = x1 - 1; i <= x2 - 1; i++)
                curr[y - 1][i] = c;
        }
        else if (ans[0] == "K")
        {
            int x1, y1, x2, y2;
            x1 = stoi(ans[1]);
            y1 = stoi(ans[2]);
            x2 = stoi(ans[3]);
            y2 = stoi(ans[4]);
            c = ans[5];
            for (int i = y1 - 1; i <= y2 - 1; i++)
            {
                for (int j = x1 - 1; j <= x2 - 1; j++)
                {
                    curr[i][j] = c;
                }
            }
        }
        else if (ans[0] == "F")
        {
            int x, y;
            x = stoi(ans[1]);
            y = stoi(ans[2]);
            c = ans[3];
            string p = curr[y - 1][x - 1];
            vector<vector<string>> kp;
            kp = curr;
            for (int i = 0; i < curr.size(); i++)
            {
                for (int j = 0; j < curr[0].size(); j++)
                {
                    if (curr[i][j] == p)
                        curr[i][j] = c;
                    if (i != 0 && kp[i - 1][j] == p)
                        curr[i][j] = c;
                    if (i != curr.size() - 1 && kp[i + 1][j] == p)
                        curr[i][j] = c;
                    if (j != 0 && kp[i][j - 1] == p)
                        curr[i][j] = c;
                    if (j != curr[0].size() - 1 && kp[i][j + 1] == p)
                        curr[i][j] = c;
                }
            }
        }
        else if (ans[0] == "S")
        {
            string name;
            name = ans[1];
            cout << name << "\n";
            for (int i = 0; i < curr.size(); i++)
            {
                for (int j = 0; j < curr[0].size(); j++)
                {
                    cout << curr[i][j];
                }
                cout << "\n";
            }
        }
        else if (ans[0] == "X")
            break;
    }

    return 0;
}
