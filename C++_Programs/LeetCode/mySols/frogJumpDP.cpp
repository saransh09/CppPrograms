#include <bits/stdc++.h>
using namespace std;

class Solution {
	unordered_map<int,bool> dp;
public:
	bool canCross(vector<int> & stones) {
		if (stones.size()<2) return true;
		if (stones[1]!=1) return false;
		return canReach(0,0,stones);
	}
	bool canReach(int idx, int k, vector<int> & stones) {
		int key = idx | k<<11;
		if (dp.find(key)!=dp.end()) return dp[key];
		if (idx==stones.size()) return true;
		bool result = false;
		int target = stones[idx] + k;
		int future_stone_idx = binary_search
	}
};

int main() {


	return 0;
}