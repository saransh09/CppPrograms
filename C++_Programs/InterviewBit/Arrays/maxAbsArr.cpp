#include <bits/stdc++.h>
using namespace std;

int maxAbsArr (vector<int> & A) {
	int ans = 0;
	int max1 = INT_MIN, max2 = INT_MIN;
	int min1 = INT_MAX, min2 = INT_MAX;
	for (int i = 0 ; i < A.size() ; i++) {
		min1 = min(min1, A[i]+i);
		min2 = min(min2, A[i]-i);
		max1 = max(max1, A[i]+i);
		max2 = max(max2, A[i]-i);
	}
	ans = max(ans, max1 - min1);
	ans = max(ans, max2 - min2);
	return ans;
}

int main() {

	return 0;
}