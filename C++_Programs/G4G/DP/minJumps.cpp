#include <bits/stdc++.h>
using namespace std;

class Solution{
	int minJumpsHelper(vector<int> jumps, int l, int h){
		if(h==l) return 0;
		if(arr[l]==0) return INT_MAX;
		int min = INT_MIN;
		for(int i = l+1 ; i<=h && i <= l + jumps[l] ; i++){
			int ju = minJumpsHelper(jumps,l+1,h);
			if(ju!=INT_MAX && ju +1 < min) min = ju + 1;
		}
		return min;
	}
	int minJumpsHelperDP(vector<int> arr,int n){
		vector<int> jumps(n);
		if(n==0 || arr[0]) return INT_MAX;
		jumps[0] = 0;
		for(int i = 1 ; i < n ; i++){
			jumps[i] = INT_MAX;
			for(int j = 0 ; j < i ; j++){
				if(i <= j + arr[j] && jumps[i] != INT_MAX){
					jumps[i] = min(jumps[i],jumps[i+1]);
					break;
				}
			}
		}
		return jumps[n];
	}
public:
	int minJumps(vector<int> jumps){
		return minJumpsHelper(jumps,0,jumps.size()-1);
	}
};

int main() {

	return 0;
}