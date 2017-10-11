#include <bits/stdc++.h>
using namespace std;

void backtrace(vector<vector<int> > dp,string a, string b ,int i, int j, string & sol){
	if(i==-1 || j==-1) return;
	else if(a[i-1]==b[j-1]) {
		backtrace(dp,a,b,i-1,j-1,sol);
		sol.push_back(a[i-1]);
	}
	else{
		if(dp[i][j-1]>dp[i-1][j]) backtrace(dp,a,b,i,j-1,sol);
		else backtrace(dp,a,b,i-1,j,sol);
	}
}

string adfruits(string a, string b){
	vector<vector<int> > dp(a.size()+1,vector<int>(b.size()+1));
	for(int i = 0 ; i <= a.size() ; i++) dp[i][0] = 0;
	for(int j = 0 ; j <= b.size() ; j++) dp[0][j] = 0;
	for(int i = 1 ; i <= a.size() ; i++) {
		for(int j = 1 ; j <= b.size() ; j++) {
			if(a[i-1]==b[i-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	string sol;
	backtrace(dp,a,b,a.size(),b.size(),sol);
	return sol;
}

int main() {
	string s;
	while(!cin.eof()){
		string a,b;
		cin>>a>>b;
		string sol = adfruits(a,b);
		cout<<sol<<endl;
	}
	return 0;
}