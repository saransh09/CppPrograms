#include <iostream>
using namespace std;

int calcSquares(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	int count = 0;
	for(int i = n ; i > 0 ; i--){
		count += i*i;
	}
	return count;
}

int main() {
	int n[100]; 
	int i;
	for(i = 0 ; i < 100 ; i++){
		cin>>n[i];
		if(n[i]==0) break;
	}
	for(int j = 0 ; j < i ; j++){
		cout<<calcSquares(n[j])<<endl;
	}
	return 0;
}