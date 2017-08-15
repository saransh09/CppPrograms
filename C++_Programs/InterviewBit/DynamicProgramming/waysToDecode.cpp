#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int numDecoding(string s){
		if(s.size()==0) return 0;
		if(s.size()==1){
			if(s[0]=='0') return 0;
			else return 1;
		}
		vector<int> temp(s.size()+1);
		for(int i=2; i<(int)temp.size(); i++){
			temp[i]=0;
			if(s[i-1]-'0'>0) temp[i]=temp[i-1];
			if(s[i-1]=='0' && s[i-2]>'2') return 0;
			if((s[i-2]-'0'<2 && s[i-2]-'0'>0)||(s[i-2]-'0'==2 && s[i-1]-'0'<=6)) temp[i]=temp[i]+temp[i-2];
		}
		return temp[temp.size()-1];
	}
};

int main() {

	return 0;
}