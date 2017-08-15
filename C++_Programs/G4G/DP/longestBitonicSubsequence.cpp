#include <bits/stdc++.h>
using namespace std;

int lbs(vector<int> arr){
	int n = arr.size();
	vector<int> dpi(n), dpd(n);
	for(int i = 0 ; i < n ; i++) dpi[i] = 1;
	for(int i = 1 ; i < n ; i++)
		for(int j = 0 ; j < i ; j++)
			if(arr[i]>arr[j] && dpi[i] < dpi[j] + 1) dpi[i] = dpi[j] + 1;
	for(int i = n-2 ; i < n ; i++) dpd[i] = 1;
	for(int i = n-1 ; i < n ; i++)
		for(int j = 0 ; j < i ; j++)
			if(arr[i] > arr[j] && dpd[i] < dpd[j] + 1) dpd[i] = dpd[j] + 1;
	int max = dpi[0] + dpd[0] - 1;
	for(int i = 1 ; i < n ; i++){
		if(dpi[i] + dpd[i] - 1 > max){
			max = dpi[i] + dpd[i] - 1;
		}
	}
	return max;
}

int main() {

	return 0;
}