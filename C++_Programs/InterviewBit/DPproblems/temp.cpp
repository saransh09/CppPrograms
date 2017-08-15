#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int> coins, int m, int V) {
	if (V==0) {
		return 0;
	}
	int res = INT_MAX;
	for (int i = 0 ; i < m ; i++) {
		if (coins[i] <= V) {
			int sub_res = minCoins(coins, m, V-coins[i]);
			if (sub_res!=INT_MAX && sub_res + 1 < res) {
				res = sub_res + 1;
			}
		}
	}
	return res;
}

int minCoinsDP(vector<int> coins, int m, int V) {
	int table[V+1];
	table[0] = 0;
	for (int i = 1 ; i<=V ; i++) {
		table[i] = INT_MAX;
	}
	for (int i = 1 ; i <= V ; i++) {
		for (int j = 0 ; j < m ; j++) {
			if (coins[j] <= i) {
				int sub_res = table[i - coins[j]];
				if (sub_res!=INT_MAX && sub_res + 1 < table[i]) {
					table[i] = sub_res + 1;
				}
			}
		}
	}
	return table[V];
}

int main() {
	vector<int> coins;
	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(5);
	coins.push_back(10);
	coins.push_back(20);
	cout<<minCoinsDP(coins, 5, 28392);
	return 0;
}