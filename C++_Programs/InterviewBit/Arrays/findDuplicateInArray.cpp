#include <bits/stdc++.h>
using namespace std;

int repeatedNumber(const vector<int> & A) {
	vector<bool> v(A.size(),true);
	for (int i = 0 ; i < A.size() ; i++) {
		if (v[A[i]]) {
			v[A[i]] = false;
		}
		else {
			return A[i];
		}
	}
}

int main() {
	vector<int> A;
	A.push_back(3);
	A.push_back(1);
	A.push_back(4);
	A.push_back(1);
	A.push_back(4);
	A.push_back(1);
	// A.push_back();
	// A.push_back();
	// A.push_back();
	cout<<repeatedNumber(A);
	return 0;
}