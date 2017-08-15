#include <bits/stdc++.h>
using namespace std;

#define R 6
#define C 5

int min(int a, int b, int c) {
	if (a < b) {
		if (a < c) {
			return a;
		}
		else {
			return c;
		}
	}
	return b;
}

void printMaxSquare(bool M[R][C]) {
	int S[R][C];
	int max_of_s = -1;
	int max_i, max_j;
	for (int i = 0 ; i < R ; i++) {
		S[i][0] = M[i][0];
	}
	for (int j = 0 ; j < C ; j++) {
		S[0][j] = M[0][j];
	}
	for (int i = 1 ; i < R ; i++) {
		for (int j = 0 ; j < C ; j++) {
			if (M[i][j]==1) {
				S[i][j] = min(S[i][j-1],S[i-1][j],S[i-1][j-1]) + 1;
			}
			else {
				S[i][j] = 0;
			}
		}
	}
}

int main() {

	return 0;
}