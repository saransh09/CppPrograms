#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) {
	return ( a > b ) ? a : b;
}
int knapsack(int W, int *wt, int *val, int n) {
	int K[n+1][W+1];
	for (int i=0; i<=n;i++) {
		for (int j=0;j<=W;j++) {
			if (i==0 || j==0) {
				K[i][j] = 0;
			}
			else if (wt[i-1]<=j) {
				K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]], K[i-1][j]);
			}
			else {
				K[i][j] = K[i-1][j];
			}
		}
	}
	return K[n][W];
}
int main() {
	int wt[] = {2,2,3,5};
	int val[] = {4,3,7,9};
	int W = 9;
	int n = sizeof(val)/sizeof(val[0]);
	cout<<"The maximum value possible is : "<<knapsack(W,wt,val,n);
	return 0;
}