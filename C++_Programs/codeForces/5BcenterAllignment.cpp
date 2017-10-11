#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> s;
	int c = 0;
	string x;
	while(getline(cin,x)){
		c++;
		s.push_back(x);
	}
	int maxLen = 0;
	for(int i = 0 ; i < c ; i++){
		maxLen = max(maxLen,(int)s[i].length());
	}
	vector<string> sol(c+2);
	for(int i = 0 ; i <= c+1 ; i++){
		if(i==0 || i==c+1){
			string temp;
			for(int i = 0 ; i <= maxLen+1 ; i++) {
				temp += '*';
			}
			sol[i] = temp;
		}
		else{
			string temp(maxLen+2,' ');
			temp[0] = '*' ;
			temp[maxLen + 1] = '*';
			sol[i] = temp;
		}
	}
	int j = 1,ss;
	for (int i=0; i<c; i++)
		ss=(maxLen-(int)s[i].size()),
		j +=(ss&1),
		cout<<"*"<<string(ss/2+(ss&1)*(c&1),' ')<<s[i]<<string(ss-ss/2-(ss&1)*(c&1),' ')<<"*"<<endl;
	cout<<string(maxLen+2,'*')<<endl;
	// for(int i = 0 ; i < c ; i++){
	// 	int si = s[i].size();
	// 	int beg = (maxLen - si)/2;
	// 	int j = 0;
	// 	while(s[i][j]!='\0') {
	// 		sol[i+1][beg+1] = s[i][j];
	// 		j++;
	// 		beg++;
	// 	}
	// }
	// for(int i = 0 ; i < (int) sol.size() ; i++) cout<<sol[i]<<endl;
	return 0;
}