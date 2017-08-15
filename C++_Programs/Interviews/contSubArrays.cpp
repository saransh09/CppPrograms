#include <bits/stdc++.h>
using namespace std;

void countHelper(vector<int> num, int k, int & c) {
	for(int i = 0 ; i < num.size() ; i++) {
		for(int j = i ; j < num.size() ; j++) {
			if(i==j){
				if(num[i]<k) c++;
			}
			else{
				int prod = 1;
				for(int k = 0 ; k <= j; k++) {
					prod *= num[k];
				}
				if(prod<k) c += (j - i) + 1;
			}

		}
	}
}

int count(vector<int> num, int k){
	int c = 0;
	countHelper(num,k,c);
} 

int main() {

	return 0;
}