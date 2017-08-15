#include <bits/stdc++.h>
using namespace std;

int dp[50][4][6];

bool isVowel(char ch) {
	if (ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') return true;
	return false;
}

int go(string & s, int i, int c, int v) {
	if(i==(int)s.length()) return 2;
	if(dp[i][c][v]!=-1) return dp[i][c][v];
	if (s[i]=='?') {
		int opt1 = (c>=4) ? 1 : go(s, i+1, min(c+1,5), 0);
		int opt2 = (v>=2) ? 1 : go(s, i+1, 0, min(v+1,3));
		return dp[i][c][v] = opt1 | opt2;
	}
	if(isVowel(s[i])){
		if(v>=2){
			return dp[i][c][v]=1;
		}
		return dp[i][c][v] = go(s, i+1, 0, min(v+1,3));
	}
	if (c >= 4) return dp[i][c][v] = 1;
  	return dp[i][c][v] = go(s, i + 1, min(c + 1, 5), 0);
}

void solve(vector<string> & v, vector<string> & sol) {
	for(int i=0; i<v.size() ; i++) {
		string s = v[i];
		memset(dp,-1,sizeof(dp));
		int op = go(s,0,0,0);
		if(op==1) {
			sol.push_back("BAD");
		}	
		else if (op == 2) sol.push_back("GOOD");
		else {
			sol.push_back("MIXED");
		}
	}
}

int main() {
	vector<string> v = {"FFFF?EE","HELLOWORLD","ABCDEFGHIJKLMNOPQRSTUVWXYZ", "HELLO?ORLD", "AAA"};
	vector<string> sol;
	solve(v,sol);
	for(int i = 0 ; i < sol.size() ; i++) {
		cout<<sol[i]<<endl;
	}
	return 0;
}