#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) {
	return (a>b) ? a : b;
}

int lcsRec(string X, string Y, int m, int n) {
	if (m==0 || n==0) {
		return 0;
	}
	if (X[m-1]==Y[m-1]) {
		return 1 + lcsRec(X,Y,m-1,n-1);
	}
	else {
		return max(lcsRec(X,Y,m-1,n) , lcsRec(X,Y,m,n-1));
	}
}

int lcsDP(string a, string b, int m, int n) {
	int L[m+1][n+1];
	for (int i = 0 ; i <= m ; i++) {
		for (int j = 0 ; j <= n ; j++) {
			if (i==0 || j==0) {
				L[i][j] = 0;
			}
			else if (a[i]==b[j]) {
				L[i][j] = L[i-1][j-1] + 1;
			}
			else {
				L[i][j] = max(L[i-1][j], L[i][j-1]);
			}
		}
	}
	return L[m][n];
}

int main() {
	string a = "abcdsaossdoihasijghaiudfghiusdghwifgnfkodsokbmeroimbeoritmgbirembijrebmmberbmrtbmkorbmrkobtmtbmerkotbsdvjajghasighiu";
	string b = "skjdfnsdfkndajgbhagbiudbfiusdhfiusdhfsaiughiuasghuiklkbmerboim3r9imr3tib3iutbn35iun34uign34ign43uign34ijgn43ijgn4jign";
	cout<<lcsDP(a,b,a.length(),b.length());
	return 0;
}