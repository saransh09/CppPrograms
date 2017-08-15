#include <iostream>
using namespace std;

int fibDP(int n) {
	int f[n+1];
	int i;
	f[0] = 0;
	f[1] = 1;
	for (i=2 ; i<=n ; i++) {
		f[i] = f[i-1] + f[i-2]; 
	}
	return f[n];
}

// DP Space optimized
int fibDPSO(int n) {
	int a=0, b=1;
	int c;
	for (int i=2;i<=n;i++) {
		c = a+ b;
		a = b;
		b = c;
	}
	return b;
}

// Method 4
void multiply(int F[2][2], int M[2][2]) {
	int x = F[0][0]*M[0][0] + F[0][1]*M[1][0];
	int y = F[0][0]*M[0][1] + F[0][1]*M[1][1];
  	int z = F[1][0]*M[0][0] + F[1][1]*M[1][0];
  	int w = F[1][0]*M[0][1] + F[1][1]*M[1][1];
  	F[0][0] = x;
  	F[0][1] = y;
  	F[1][0] = z;
  	F[1][1] = w;
}
int power(int F[2][2], int n) {
	int M[2][2] = {{1,1},{1,0}};
	for (int i=2;i<=n;i++) {
		multiply(F,M);
	}
}
int fib(int n) {
	int F[2][2] = {{1,1},{1,0}};
	if (n==0) {
		return 0;
	}
	power(F,n-1);
}

// Method 5




// Main function
int main() {
	// cout<<"Enter n : ";
	// int n;
	// cin>>n;
	cout<<fibDPSO(942234);
	return 0;
}