#include <bits/stdc++.h>
using namespace std;

int calcMax(vector<int> a, vector<int> b){
	int la = a.size();
	int lb = b.size();
	int l = max(la,lb);
	int dp[2][l+1];
	dp[0][0] = dp[1][0] = 0;
	for(int i = 1 ; i <= min(la,lb) ; i++){
		if(a[i]!=b[i]){
			dp[0][i] = dp[0][i-1] + a[i];
			dp[1][i] = dp[1][i-1] + b[i];
		}
		else{
			dp[0][i] = max(dp[0][i-1] + a[i] , dp[0][i-1] + b[i]);
			dp[1][i] = max(dp[1][i-1] + a[i] , dp[1][i-1] + b[i]);
		}
	}
	if(la>lb){
		for(int i = lb ; i <= l ; i++) dp[0][i] = dp[0][i-1] + a[i];
		return dp[0][l+1];
	}
	else{
		for(int i = la ; i <= lb ; i++) dp[1][i] = dp[1][i-1] + b[i];
		return dp[1][l+1];
	}
}

int main() {
	while(1){
		int la;
		cin>>la;
		if(la==0) break;
		vector<int> a;
		for(int i = 0 ; i < la ; i++){
			cin>>a[i];
		}
		int lb;
		cin>>lb;
		vector<int> b;
		for(int i = 0 ; i < lb ; i++){
			cin>>b[i];
		}
		cout<<calcMax(a,b)<<endl;
	}
	return 0;
}