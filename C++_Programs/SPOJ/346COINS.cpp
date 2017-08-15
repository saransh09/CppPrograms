#include <bits/stdc++.h>
using namespace std;

unsigned long long int calcMaxValDP(long long n) {
	if(n==0) return 0;
	vector<int> dp(n+1);
	for(int i = 0 ; i <= n ; i++) dp[i] = i;
	for(int i = 2 ; i <= n ; i++){
		dp[i] = max(dp[i],dp[i/2]+dp[i/3]+dp[i/4]);
	}
	return dp[n];
}

void calcMaxValRec(long long n, unsigned long long int & maxVal, unsigned long long int curr){
	if(n==0 || curr<maxVal) return;
	else if (curr > maxVal) maxVal = curr;
	calcMaxValRec(n/2,maxVal,curr-n + n/2 + n/3 + n/4);
	calcMaxValRec(n/3,maxVal,curr-n + n/2 + n/3 + n/4);
	calcMaxValRec(n/4,maxVal,curr-n + n/2 + n/3 + n/4);
}

unsigned long long int calcMaxVal(long long n){
	if (n==0) return 0;
	// unsigned long long int maxVal = n;
	// calcMaxValRec(n,maxVal,n);
	// return maxVal;
	unsigned long long maxValue = calcMaxValDP(n);
	return maxValue;
}

int main() {
	int t = 10;
	while(t--){
		int n;
		cin>>n;
		cout<<calcMaxVal(n)<<endl;
	}
	return 0;
}