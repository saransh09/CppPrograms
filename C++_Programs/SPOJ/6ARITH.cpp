#include <bits/stdc++.h>
using namespace std;

void performAdd(string a, string b){
	
}

void performCalc(string a, char op, string b){
	if(op=='+'){
		performAdd(a,b);
	}
	else if(op=='-'){
		performSub(a,b);
	}
	else if(op=='*'){
		performMul(a,b);
	}
}

int main() {
	int t;
	cin>>t;
	string s[t];
	for(int i = 0 ; i < t ; i++){
		cin>>s[i];
	}
	for(int i = 0 ; i < t ; i++){
		string x = s[i];
		int j = 0;
		while(x[j]!='+' && x[j]!='-' && x[j]!='*'){ 
			j++;
		}
		string a,b;
		char op;
		a = x.substr(0,j);
		op = x[j];
		b = x.substr(j+1,x.length()-j);
		performCalc(a,op,b);
	}
	// char ch = '6';
	// cout<<ch<<endl<<ch-'0';
	// int x = ch - '0';
	// cout<<endl<<x;
	return 0;
}