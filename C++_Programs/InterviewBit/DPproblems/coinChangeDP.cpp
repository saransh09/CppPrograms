#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> S, int m, int n) {
	if(n==0) {
		return 1;
	}
	if (n<0) {
		return 0;
	}
	if (m<=0 && n>=1) {
		return 0;
	}
	return coinChange(S,m-1,n) + coinChange(S,m,n-S[m-1]);
}

int coinChangeDP(vector<int> S, int m, int n) {
	int table[n+1][m];
	int x,y;
	for (int i = 0 ; i < m ; i++) {
		table[0][i] = 1;
	}
	for (int i=0 ; i<n+1 ; i++) {
		for(int j=0 ; j<m;j++) {
			x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0;
			y = (j>=1) ? table[i][j-1] : 0;
			table[i][j] = x + y;
		}
	}
	return table[m][n];
}

int main() {	
	vector<int> S;
	S.push_back(1);
	S.push_back(2);
	S.push_back(3);
	int m = S.size();
	cout<<coinChangeDP(S,3,4); 
	return 0;
}