#include <bits/stdc++.h>
using namespace std;
//Method 1
// Normal recursion based approach
int binCoeffRec(int n, int k) {
	if (k==0 || k==n) {
		return 1;
	}
	else {
		return (binCoeffRec(n-1,k-1) + binCoeffRec(n-1,k));
	}
}
// Method 2
int min(int a, int b) {
	return (a<b)? a: b;
}
int binCoeffDP(int n, int k) {
	int C[n+1][k+1];
	for (int i=0;i<=n;i++) {
		for (int j=0;j<=k;j++) {
			if (j == 0 || j==i) {
				C[i][j] = 1;
			}
			else {
				C[i][j] = C[i-1][j-1] + C[i-1][j];
			}
		}
	}
	return C[n][k];
}
//Main Function
int main() {
	// cout<<binCoeffRec(1000,10);
	cout<<binCoeffDP(1000,10);
}