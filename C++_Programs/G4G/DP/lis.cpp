#include <bits/stdc++.h>
using namespace std;

class Solution{
	// O(2^n) solution using Recursion
	int lisHelper(vector<int> v,int n, int & result){
		if(n==1) return 1;
		int res, maxEndingHere = 1;
		for(int i = 1 ; i < n ; i++){
			res = lisHelper(v,i,result);
			if(v[i-1]<v[n-1] && res+1>maxEndingHere) maxEndingHere = res + 1;
		}
		if(result < maxEndingHere){
			result = maxEndingHere;
		}
		return maxEndingHere;
	}
	// O(n^2) solution using DP
	int lisHelperDP(vector<int> v){
		int n = v.size();
		vector<int> lis(n);
		int max = 0;
		for(int i = 0 ; i < n ; i++) lis[i] = i;
		for(int i = 1 ; i < n ; i++){
			for(int j = 0 ; j < i ; j++){
				if(v[i]>v[j] && lis[i] < lis[j] + 1){
					lis[i] = lis[j] + 1;
				}
			}
		}
		for(int i = 0 ; i < n ; i++){
			if(max < lis[i]) max = lis[i];
		}
		return max;
	}
	//  O(nlogn) solution :
	// ----------------TODO ------------------
public:
	int lis(vector<int> v){
		// int result = 1;
		// lisHelper(v,v.size(),result);
		// return result;
		return lisHelperDP(v);
	}
};

int main() {
	Solution s;
	cout<<s.lis({23,423,432,6,46,234,12,412,4,13,1,31,2,52,35,436,435,76,8,68,46,3,5,123,12,3,123,3,2,32,31,3,123,12
		,31,23,123,13,412,4,46,7,77,85,734,423,4,3467,68,46,25,6457,3,51,53,7,47,5,346,3,47,69,8,4,25,24,23,6,4,275,5,4,24})<<endl;
	return 0;
}