#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<vector<char> > chess(8,vector<char>(8,'W'));
	for(int i = 0 ; i < 8 ; i++) {
		string s;
		cin>>s;
		for(int j = 0 ; j < s.size() ; j++) {
			chess[i][j] = s[j];
		}
	}
	int row = 0, col = 0;
	for(int i = 0 ; i < 8 ; i++){
		bool b = true;
		for(int j = 0 ; j < 8 ; j++){
			if(chess[i][j]=='W'){
			 b = false;
			 break;
			}
			else continue;
		}
		if(b) row++;
	}
	for(int j = 0 ; j < 8 ; j++){
		bool b = true;
		for(int i = 0 ; i < 8 ; i++){
			if(chess[i][j]=='W'){
				b = false;
				break;
			}
			else continue;
		}
		if(b) col++;
	}
	if(row==8 || col==8){ 
		cout<<row;
		return 0;
	}
	else {
		cout<<row+col;
	}
	return 0;
}