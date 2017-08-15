#include <bits/stdc++.h>
using namespace std;

int solutionsOfLinearEquation(vector<int> coeff,int start, int end, int rhs) {
	if (rhs==0) {
		return 1;
	}
	int result = 0;
	for (int i=start; i<=end; i++) {
		if (coeff[i]<=rhs) {
			result += solutionsOfLinearEquation(coeff, i, end, rhs-coeff[i]);
		}
	}
	return result;
}

int solutionsOfLinearEquationDP(vector<int> coeff, int start, int end, int rhs) {
	vector<int> dp(0, rhs+1);
	dp[0]=1;
	for (int i=start ; i<=end ; i++) {
		for (int j=coeff[i] ; )
	}
}

int main() {
	int rhs;
	cout<<"Enter the number of variables : ";
	int n;
	cin>>n;
	vector<int> coeff;
	for (int i=0; i<n ; i++) {
		int temp;
		cin>>temp;
		coeff.push_back(temp);
	}
	cout<<"Enter the rhs of the equation : ";
	cin>>rhs;
	int sol = solutionsOfLinearEquation(coeff, 0, n-1, rhs);
	cout<<sol<<endl;
	return 0;
}