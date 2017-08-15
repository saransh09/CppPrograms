#include <bits/stdc++.h>
using namespace std;

int cutRod(vector<int> & price){
	int val[price.size()+1];
	val[0]=0;
	for(int i = 1 ; i <= price.size() ; i++){
		int max_val = INT_MIN;
		for(int j = 0 ; j < i ; j++){
			max_val = max(max_val,price[j]+val[i-j-1]);
		}
		val[i]=max_val;
	}
	return val[price.size()];
}

int main() {
	vector<int> prices = {1,5,8,9,10,17,17,20};
	cout<<cutRod(prices);
	return 0;
}

