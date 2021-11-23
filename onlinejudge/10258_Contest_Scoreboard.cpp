//10258 Contest Scoreboard
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t; //testcases
	cin>>t;
	while(t--)
	{
	    int c,q,p; // c: CONTESTANT NO , q: QUESTION NO , p: penalty time
	    string s; //Status of online judge on question
	    unordered_map<int,pair<int,int>>contestant;
	    vector<vector<int>>status(101,vector<int>(10));
		pair<int,int>a(0,0);
	    while(cin>>c>>q>>p>>s)
	    {
	        if(contestant.find(c)==contestant.end()) contestant[c]=a;  //if contestant is new
			if(s=="I")
			{
				status[c][q]+=20; //penalty of 20min for wrong solution
			}
			else if(s=="C")
			{
				contestant[c].first+=1;
				contestant[c].second+=p+status[c][q];
			}
	    }
	}
	
	return 0;
}

//Output:
//1 2 66
//3 1 11
