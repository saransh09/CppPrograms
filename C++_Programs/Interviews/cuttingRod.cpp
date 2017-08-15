#include <bits/stdc++.h>
using namespace std;

int cutRod(vector<int> price) {
	int n = price.size();
	int val[n+1];
	val[0]=0;
	for(int i = 1; i <= n ; i++) {
		int m = INT_MIN;
		for(int j = 0 ; j < i ; j++) {
			m = max(m,price[i-j-1]+val[j]);
		}
		val[i] = m;
	}
	return val[n];
}

int main() {
	vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
	cout<<cutRod(price)<<endl;
	return 0;
}