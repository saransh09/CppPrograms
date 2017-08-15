#include <bits/stdc++.h>
using namespace std;
int maxSubArraySum(int a[], int n) {
	int maxSoFar = INT_MIN, maxEndingHere = 0;
	for (int i=0;i<n;i++) {
		maxEndingHere = maxEndingHere + a[i];
		if (maxSoFar < maxEndingHere) {
			maxSoFar = maxEndingHere;
		}
		if (maxEndingHere < 0) {
			maxEndingHere = 0;
		}
	}
	return maxSoFar;
}
int main() {
	int a[] = {-2,-3,4,-1,-2,1,5,-3};
	int n = sizeof(a)/sizeof(a[0]);
	// cout << "n = "<<n<<endl;
	cout<<"Max Contiguous Sum : "<<maxSubArraySum(a,n);
	return 0;
}