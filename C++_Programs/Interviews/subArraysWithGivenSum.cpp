#include <bits/stdc++.h>
using namespace std;

int subArraySum(vector<int> arr, int n, int sum){
	int currSum = arr[0], start = 0;
	for(int i=1 ; i<=n; i++){
		while(currSum>sum && start<i-1){
			currSum = currSum - arr[start];
			start++;
		}
		if(currSum==sum){
			cout<<"The required sum is found between "<<start<<" and "<<i-1<<endl;
			return 1;
		}
		if(i<n) currSum = currSum + arr[i];
	}
	cout<<"No Sub array found ";
	return 0;
}

int main() {
	vector<int> arr = {15,2,4,8,9,5,10,23};
	int n = arr.size();
	int sum=23;
	subArraySum(arr,n,sum);
	return 0;
}