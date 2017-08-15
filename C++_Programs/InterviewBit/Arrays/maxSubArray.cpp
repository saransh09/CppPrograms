#include <bits/stdc++.h>
using namespace std;

int maxSubArray(const vector<int> & A) {
	int n = A.size();
	int currsum = 0, maxsum = INT_MAX;
	for (int i = 0 ; i < n ; i++) {
		currsum += A[i];
		maxsum = max(currsum, maxsum);
		if (currsum < 0) {
			currsum = 0;
		} 
	}
	return 	maxsum;
}

int main() {

	return 0;
}