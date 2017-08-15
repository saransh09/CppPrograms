#include <bits/stdc++.h>
using namespace std;

void swap (char & a, char & b) {
	char temp = a;
	a = b;
	b = temp;
}

void permute(string & a,int l, int r ,vector<string> sol) {
	if (l==r) {
		sol.push_back(a);
	}
	else {
		for (int i = 1; i <= r ; i++) {
			// swap((a+1),(a+i))
			a[]
		}
	}

}

int main() {
	string a = "abc";
	vector<string> sol;
	permute(a,0,a.length()-1,sol);
	return 0;
}