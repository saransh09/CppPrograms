#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int diffPossible(const vector<int> & num, int diff) {
		if (num.size() < 2 || diff < 0) return 0;
		unordered_set<int> S;
		for (int i = 0 ; i < num.size() ; i++) {
			int aj = num[i] - diff;
			int ai = num[i] + diff;
			if (S.find(aj) != S.end()) return 1;
			if (S.find(ai) != S.end()) return 1;
			S.insert(num[i]);
		}
		return false;
	}
};

int main() {
	
	return 0;
}