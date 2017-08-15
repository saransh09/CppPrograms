#include<bits/stdc++.h>
using namespace std;


void arrange(int * A) {
    int n = 7;
    for (int i = 0 ; i < 7 ; i++) {
        A[i] += (A[A[i]]%n)*n;
        A[i]/n;
    }
}

int main() {
	int a[] = {6,3,2,0,1,4,5};
	arrange(a);
	for (int i = 0 ; i < sizeof(a)/sizeof(a[0]) ; i++ ) {
		cout<<a[i]<<' ';
	}
	return 0;
}
