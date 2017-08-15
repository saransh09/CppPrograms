#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) {
	return (a>b) ? a : b;
}

int knapSack(int W, int *wt, int *val, int n) {
	if (n==0 || W==0)
		return 0;
	if (wt[n-1]>W)
		return knapSack(W,wt,val,n-1);
	else return max(val[n-1] + knapSack(W-wt[n-1], wt,val, n-1),
					knapSack(W,wt,val, n-1));
}

int knapSackDP(int W, int *wt, int *val, int n) {
	int i,w;
	int K[n+1][W+1];
	for (i=0 ; i<=n ; i++) {
		for (w=0 ; w <= W; w++) {
			if (i==0 || w==0) {
				K[i][w] = 0;
			}
			else if (wt[i-1] <= w) {
				K[i][w] = max(val[i-1] + K[i-1][w - wt[i-1]], K[i-1][w]);
			}
			else {
				K[i][w] = K[i-1][w];
			}
		}
	}
	return K[n][w];
}

int main() {
	int val[] = {60,100, 120};
	int wt[] = {10,20,30};
	int W = 50;
	int n = sizeof(val)/sizeof(val[0]);
	printf("%d\n", knapSackDP(W,wt,val,n));
	return 0;
}