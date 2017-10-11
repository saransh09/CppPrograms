#include <bits/stdc++.h>
using namespace std;

void calcMaxValRec(long long n, unsigned long long & maxVal, unsigned long long curr){
	if(n==0 || curr<maxVal) return;
	else if (curr > maxVal) maxVal = curr;
	calcMaxValRec(n/2,maxVal,curr-n + n/2 + n/3 + n/4);
	calcMaxValRec(n/3,maxVal,curr-n + n/2 + n/3 + n/4);
	calcMaxValRec(n/4,maxVal,curr-n + n/2 + n/3 + n/4);
}

unsigned long long int calcMaxVal(long long n){
	if(n==0) return 0;
	unsigned long long maxVal = 0;
	calcMaxValRec(n,maxVal,0);
	return maxVal;
}

int main() {
	int t = 10;
	while(t--){
		int n;
		cin>>n;
		cout<<calcMaxVal(n)<<endl;
	}
	return 0;
}