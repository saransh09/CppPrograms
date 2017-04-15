#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
	long long int x=32,y;
	vector<int> bit_x, bit_y;
	int num = 0;
	while(x>0) {
		bit_x.push_back(x%2);
		x /= 2;
		num++;
	}

	for(int j=0,i=num;j<i;j++,i--) {
		bit_x[i] = bit_x[j];
	}
	while(y>0) {
		bit_y.push_back(y%2);
		y /= 2;
	}
	for(int k = 0;k <= num;k++) {
		cout<<bit_x[k]<<'\t';
	}
	// bit_y.reverse();
}