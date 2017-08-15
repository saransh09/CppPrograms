#include <bits/stdc++.h>
using namespace std;
bool isSubset(int *set, int n, int sum) {
	if (sum==0) {
		return true;
	}
	if (n==0 && sum!=0) {
		return false;
	}
	if (set[n-1]>sum) {
		return isSubset(set, n-1, sum);
	}
	return isSubset(set, n-1, sum) || isSubset(set, n-1, sum - set[n-1]);
}
bool isSubsetDP(int *set, int n, int sum) {
	bool subset[sum+1][n+1];
	for (int i=0; i<=n;i++) {
		subset[0][i] = true;
	}
	for (int i = 1; i<=sum ; i++) {
		subset[i][0] = false;
	}
	for (int i=1; i<=sum; i++) {
		for (int j=1; j<=n; j++) {
			subset[i][j] = subset[i][j-1];
			if (i >= set[j-1]) {
				subset[i][j] = subset[i][j] || subset[i-set[j-1]][j-1];
			}
		}
	}
	return subset[sum][n];
}
int main() {
	int set[] = {3,34,4,12,5,2};
	int sum=9;
	cout<<isSubsetDP(set,6,sum);
	return 0;
}