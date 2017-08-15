#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	string s[t];
	for(int i = 0 ; i < t ; i++) cin>>s[i];
	for(int i = 0 ; i < t ; i++){
		stack<char> br, op;
		int j = 0;
		while(s[i][j]!='\0'){
			if(s[i][j]=='(') br.push(s[i][j]);
			else if(s[i][j]== '+' || s[i][j]=='-' || s[i][j]=='*' || s[i][j]=='/' || s[i][j]=='^') op.push(s[i][j]);
			else if(s[i][j]==')'){
				if(!br.empty()) br.pop();
				char opr = op.top();
				if(!op.empty()) op.pop();
				cout<<opr;
			}
			else{
				cout<<s[i][j];
			}
			j++;
		}
		cout<<endl;
	}
	return 0;
}