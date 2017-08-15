#include <bits/stdc++.h>
using namespace std;

void printAllSubsets(vector<int> arr, int n, int sum) {
	if(n==0 || sum<0) return;
	vector<vector<bool> > dp(n,vector<bool>(sum+1));
	for(int i = 0 ; i < n ; i++) dp[i][0] = true;
	if(arr[0]<=sum) dp[0][arr[0]] = true;
	for(int i = 1; i < n ; i++) {
		for(int j = 0 ; j < sum + 1; j++) {
			
		}
	} 
}

int main() {

	return 0;
}