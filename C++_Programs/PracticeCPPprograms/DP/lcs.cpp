#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) {
	return (a<b) ? b : a;
}
int lcsNAIVE(char *X, char *Y, int m, int n) {
	if (m==0 || n==0) {
		return 0;
	}

	if (X[m-1] == Y[n-1]) {
		return 1 + lcsNAIVE(X,Y,m-1,n-1);
	}
	else {
		return max(lcsNAIVE(X,Y,m,n-1),lcsNAIVE(X,Y,m-1,n));
	}
}
int lcsDP(char *X, char *Y, int m, int n) {
	int L[m+1][n+1];
	for (int i = 0 ; i <= m ; i++) {
		for (int j = 0 ; j <= n ; j++ ) {
			if ( i == 0 || j == 0 ) {
				L[i][j] = 0;
			}
			else if (X[i-1] == Y[j-1]) {
				L[i][j] = 1 + L[i-1][j-1];
			}
			else {
				L[i][j] = max(L[i-1][j],L[i][j-1]);
			}
		}
	}
	return L[m][n];
}
int main() {
	char X[] = "AAJDAAHASIUDHIASUHSUIDGHSDUIGHSOFHAIFHAUIFHFHGHADGHJDFSIDJFHDAIUFHUIDHAOIFIO";
	char Y[] = "AJDASDASKDNAASDHBJHBDDBHDBAJHBASBASHJBADKJFNHDJFNSDJFBSDFIJBSDFISJDFBSJDFBSDJIFBSDJFBSDD";
	int m = strlen(X);
	int n = strlen(Y);
	// cout<<"Length is : "<<lcsNAIVE(X,Y,m,n);
	cout<<"Length is : "<<lcsDP(X,Y,m,n);
	return 0;
}