#include <iostream>
#include <string>
using namespace std;

int BF_match(string text, string pattern){
	int n = text.length();
	int m = pattern.length();
	int isAMatch = 0;
	for(int i = 0 ; i <= n-m ; i++){
		int j;
		for( j = 0 ; j < m ; j++){
			if(text[i+j]==pattern[j]) continue;
			else break;
		}
		if(j==m) isAMatch = 1;
	}
	return isAMatch;
}

int main() {
	string text = "abcdeabsdbadiaosdoiasdhasoidhasiodasoid";
	string pattern = "iasdhaso";
	cout<<BF_match(text,pattern)<<endl;
	return 0;
}