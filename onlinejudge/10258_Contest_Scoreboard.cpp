//10258 Contest Scoreboard
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

bool compare(pair<int,pair<int,int>>a,pair<int,pair<int,int>>b)
{
	if(a.second.first>b.second.first) return true;
	else if(a.second.first==b.second.first) //no of proble solved is same
	{
		if(a.second.second<b.second.second) return true;
		else if(a.second.second==b.second.second) //penalty is same
		{
			if(a.first<b.first) return true;
		}
	}
	return false;
}

int main() {
	
	int t; //testcases
	cin>>t;
	bool f=0;
	while(t--)
	{
	    int c,q,p; // c: CONTESTANT NO , q: QUESTION NO , p: penalty time
	    string s; //Status of online judge on question
	    unordered_map<int,pair<int,int>>contestant;
	    vector<vector<int>>status(101,vector<int>(10));
		pair<int,int>a(0,0);
		string command; // to understand end of testcases
		if(f==0) //to avoid line after no indicating testcase and line after that 
		{
		    getline(cin, command);
		    getline(cin, command);
		    f=1;
		}
	    while(getline(cin, command))
	    {
			// getline(cin, command);
			vector<string> ans;
        	ans = divide(command);
			if(ans.size()==0)break;			
			c=stoi(ans[0]);
			q=stoi(ans[1]);
			p=stoi(ans[2]);
			s=ans[3];

	        if(s=="C" || s=="I" || s=="R" || s=="U" || s=="E") if(contestant.find(c)==contestant.end()) contestant[c]=a;  //if contestant is new
			if(s=="I")
			{
				if(status[c][q]!=-1)
				{
					status[c][q]+=20; //penalty of 20min for wrong solution
				}
			}
			else if(s=="C")
			{
				if(status[c][q]!=-1)
				{
					contestant[c].first+=1; //no of problem solve ++
					contestant[c].second+=p+status[c][q]; // penalty = time for right submission + previous penalties
					status[c][q]=-1;
				}
			}
	    }
		vector<pair<int,pair<int,int>>>answer;
		for(auto it : contestant)
		{
			pair<int,pair<int,int>>b;
			b.first = it.first;
			b.second = it.second;
			answer.push_back(b);
		}
		sort(answer.begin(), answer.end(), compare);
		for(int i = 0; i < answer.size(); i++) 
		{
			cout<<answer[i].first<<" "<<answer[i].second.first<<" "<<answer[i].second.second<<"\n";
			//  contestant no            no of problem solved         penalty time
		}
		if(t) cout << "\n";
	}
	
	return 0;
}

//Output:
//1 2 66
//3 1 11
