#include <bits/stdc++.h>
using namespace std;

class Solution{
	int cutRodHelper(vector<int> prices, int n){
		if (n<=0) return 0;
		int max_val = INT_MIN;
		for(int i = 0 ; i < n ; i++){
			max_val = max(max_val,prices[i]+cutRodHelper(prices,n-i-1));
		}
		return max_val;
	}
	int cutRodHelperDP(vector<int> prices, int n){
		int val[n+1];
		val[0] = 0;
		for(int i = 1 ; i <= n ; i++){
			int max_val = INT_MIN;
			for(int j = 0 ; j < i ; j++){
				max_val = max(max_val,prices[j]+val[i-j-1]);
			}
			val[i] = max_val;
		}
		return val[n];
	}
public:
	int cutRod(vector<int> prices){
		// return cutRodHelper(prices,prices.size());
		return cutRodHelperDP(prices,prices.size());
	}
};

int main() {
	vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20, 29, 36, 49, 62, 78, 89, 99, 119, 132, 178, 188, 207, 234, 256, 278, 300, 319, 345};
	Solution s;
	cout<<s.cutRod(prices)<<endl;
	return 0;
}