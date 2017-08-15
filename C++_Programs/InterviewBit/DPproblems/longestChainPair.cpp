#include <bits/stdc++.h>
using namespace std;

int maxLengthChainPair(vector<pair<int,int> > v, int n) {
	int max = 0;
	vector<int> sol(1,n);
	for (int i = 1; i < n ; i++) {
		for (int j = 0 ; j < i ;j++) {
			if (v[i].first > v[j].second && sol[i] < sol[j] + 1) {
				sol[i] = sol[j] + 1;
			}
		}
	}
	int x = 0;
	for (int i = 0 ; i < n ; i++) {
		if (sol[i]>x) {
			x = sol[i];
		}
	}
	return x;
}

int main() {
	vector<pair<int,int> > v;
	v.push_back(make_pair(5,24));
	v.push_back(make_pair(15,25));
	v.push_back(make_pair(27,40));
	v.push_back(make_pair(50,60));
	int n = v.size();
	cout<<maxLengthChainPair(v,n);
	return 0;
}