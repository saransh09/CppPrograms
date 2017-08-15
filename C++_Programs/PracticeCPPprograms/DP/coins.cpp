#include <bits/stdc++.h>
using namespace std;
int count(int *arr, int m, int n) {
	if (n==0) {
		return 1;
	}
	if (n<0) {
		return 0;
	}
	if (m <= 0 && n >= 1) {
		return 0;
	}
	return count(arr,m-1,n) + count(arr,m,n-arr[m-1]);
}
int countDP(int *arr, int m, int n) {
	int x,y;
	int table[n+1][m];
	for (int i=0;i<m;i++) {
		table[0][i] = 1;
	}
	for (int i=1; i<n+1 ;i++) {
		for (int j=0 ; j < m ; j++) {
			x = (i - arr[j] >= 0) ? table[i-arr[j]][j] : 0;
			y = (j >= 1) ? table[i][j-1] : 0;
			table[i][j] = x + y;
		}
	}
	return table[n][m-1];
}
int main() {
	int arr[] = {1,2,5,10,20,50,100};
	int m = sizeof(arr)/sizeof(arr[0]);
	cout<<countDP(arr,m,400);
	return 0;
}