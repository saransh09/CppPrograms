#include <iostream>
using namespace std;

int main() {
	vector<char *> v;
	vector<int> s;
	for (int i=0;i<10;i++) {
		char temp[20];
		cin.getline(temp,20);
		v.push_back(temp);
		int j=0;
		int two=0;
		int three=0;
		while(v[i][j]!='\0') {
			if (v[i][j]=='K' || v[i][j]=='G') {
				two++;
			}
			if(v[i][j]=='R') {
				three++;
			}
			j++;
		}
		int p = 1;
		for(int k=0;k<two;k++) {
			p*=2;	
		}
		for(int k=0;k<three;k++) {
			p*=3;
		}
		s.push_back(p);
	}
	for(int i=0; i<s.size();i++) {
		cout<<s[i]<<endl;
	}
	return 0;
}