#include <bits/stdc++.h>
using namespace std;

class Solution{
	bool isSubsetSumRec(vector<int> arr, int index, int sum){
		if(sum==0) return true;
		if(index==(int)arr.size() && sum!=0) return false;
		if(arr[index]>sum) return isSubsetSumRec(arr,index+1,sum);
		return isSubsetSumRec(arr,index+1,sum) || isSubsetSumRec(arr,index+1,sum-arr[index]);
	}
	bool findPartition(vector<int> arr){
		int sum = 0;
		for(int i = 0 ; i < (int)arr.size() ; i++) sum += arr[i];
		if(sum%2!=0) return false;
		else return isSubsetSumRec(arr,0,sum/2);
	}
	bool findPartitionDP(vector<int> arr){
		// int n = arr.size();
		// int sum = 0;
		// for(auto it = arr.begin() ; it!=arr.end() ; it++) sum += *it;
		// if(sum%2!=0) return false;
		// bool part[sum/2 + 1][n+1];
		// for(int i = 0 ; i <=  n ; i++) part[0][i] = true;
		// for(int i = 0 ; i <= sum/2 ; i++) part[i][0] = false;
		// for(int i = 0 ; i <= sum/2 ; i++){
		// 	for(int j = 0 ; j <= n ; j++){
		// 		part[i][j] = part[i][j-1];
		// 		if(i >= arr[j-1]){
		// 			part[i][j] = part[i][j] || part[i-arr[j-1]][j-1];
		// 		}
		// 	}
		// }
		// return part[sum/2][n];
		int n = arr.size();
		int sum = 0;
		for(int i = 0 ; i < arr.size() ; i++) sum += arr[i];
		if(sum%2!=0) return false;
		bool part[sum/2+1][n+1];
		for(int i = 0 ; i <= sum/2 ; i++) part[i][0] = false;
		for(int i = 0 ; i <= n ; i++) part[0][i] = true;
		for(int i = 1 ; i <= sum/2 ; i++){
			for(int j = 1 ; j <= n ; j++){
				part[i][j] = part[i][j-1];
				if(i>=arr[j-1]){
					part[i][j] = part[i][j] || part[i - arr[j-1]][j-1];
				}
			}
		}
		return part[sum/2][n];
	}
public:
	bool isSubsetSum(vector<int> arr){
		return findPartitionDP(arr);
	}
};

int main() {
	vector<int> arr = {3,1,5,9,12};
	Solution s;
	if(s.isSubsetSum(arr)) cout<<"yes"<<endl;
	return 0;
}