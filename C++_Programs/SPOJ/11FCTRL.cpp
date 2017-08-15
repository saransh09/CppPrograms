#include <iostream>
using namespace std;

int Z(long n){
	int count = 0;
	int c = 1;
	while(n/c!=0){
		c *= 5;
		count += n/c;
	}
	return count;
}

int main() {
	int t;
	cin>>t;
	long n[t];
	for(int i = 0 ; i < t; i++) {
		cin>>n[i];
	}
	for(int i = 0 ; i < t ; i++){
		cout<<Z(n[i])<<endl;
	}
	return 0;
}