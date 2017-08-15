#include <bits/stdc++.h>
using namespace std;

bool isSubset(vector<int> v, int n, int S) {
	if (S==0) {
		return true;
	}
	if (n==0 && S>0) {
		return false;
	}
	if (v[n-1]>S) {
		return isSubset(v, n-1, S);
	}
	return isSubset(v,n-1,S-v[n-1]) || isSubset(v, n-1, S);
}

bool isSubsetDP(vector<int> v, int n, int S) {
	bool subset[S+1][n+1];
	for (int i=0 ; i<=n ; i++) {
		subset[0][i] = true;
	}
	for (int i=0 ; i<=sum ; i++) {
		subset[i][0] = false;
	}
	for (int i=1 ; i<=sum ; i++) {
		for (int j=1 ; j<=n ; j++) {
			subset[i][j] = subset[i][j-1];
			if (i >= v[j-1]) {
				subset[i][j] = subset
			} 
		}
	}
}

int main() {
	vector<int> v;
	v.push_back(3);
	v.push_back(34);
	v.push_back(4);
	v.push_back(12);
	v.push_back(5);
	v.push_back(2);
	sort(v.begin(), v.end());
	cout<<isSubset(v, v.size(), 16);
	return 0;
}