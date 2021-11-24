#include<bits/stdc++.h>
using namespace std;
 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
bool find(vector<vector<char>>box, string w, int i, int j)
{
    
}

int main()
{
    fio;
    
    int t;
    cin >> t;
    while (t--)
    {

        int m,n;
        cin >> m >> n;
        m++;
        n++;
        vector<vector<char>>box(m,vector<char>(n));
        for (int i=1; i<m; i++)
        {
            for (int j=1; j<n; j++)
            {
                cin >> box[i][j];
            }
        }
        int w = 0;
        cin >> w;
        vector<string>word(w);
        for(int i=0; i<w; i++)cin >> word[i];
        for(int k=0; k<w; k++)
        {
            bool b=0;
            for (int i=1; i<m; i++)
            {
                for (int j=1; j<n; j++)
                {
                    if(box[i][j]==word[k][0])
                    {
                        if(find(box,word[k],i,j))cout<<i<<" "<<j<<"\n";
                        b=1;
                        break;
                    }
                }
                if(b==1)break;
            }
        }

        if(t)cout << "\n";  
    }
    
    return 0;
}