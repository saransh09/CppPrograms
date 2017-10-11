#include <bits/stdc++.h>
using namespace std;

bool checkAdjacent(vector<int> h){
	for(int i = 0 ; i < h.size()-1 ; i++){
		if(h[i]!=0) {
			if(h[i+1]!=0) return false;
		}
	}
	return true;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==0) {
			cout<<0<<endl;
			continue;
		}
		else if(n==1) {
			cout<<1<<endl;
			continue;
		}
		int ans = 0;
		vector<int> heights(n);
		int minCount = INT_MAX;
		for(int i = 0 ; i < n ; i++){
			cin>>heights[i];
		}
		while(!checkAdjacent(heights)){
			minCount = INT_MAX;
			for(int i = 0 ; i < n ; i++){
				if(heights[i]!=0) minCount = min(minCount,heights[i]);
			}
			vector<bool> check(n,false);
			for(int i = 0 ; i < n - 1 ; i++){
				if(heights[i]!=0 && heights[i+1]!=0){
					check[i] = check[i+1] = true;
				}
			}
			for(int i = 0 ; i < n ; i++){
				if(heights[i]!=0 && check[i]) {
					heights[i] -= minCount;
					ans += minCount;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}