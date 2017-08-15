#include <bits/stdc++.h>
using namespace std;

struct myComparator {
	const vector<int> & value_vector;
	myComparator(const vector<int> & val_vec):
	value_vector(val_vec) {}
	bool operator()(int i1, int i2) {
		return value_vector[i1] < value_vector[i2];
	}
};

int main() {
	vector<int> a,b;
	a.push_back(9894);
	a.push_back(99967);
	a.push_back(9);
	a.push_back(849);
	a.push_back(742);
	b.push_back(8);
	b.push_back(9);
	b.push_back(9);
	b.push_back(7);
	b.push_back(9);	
	sort(a.begin(), a.end(), myComparator(b));
	for (int i = 0 ; i < a.size() ; i++) {
		cout << a[i] << ' ';
	}
}