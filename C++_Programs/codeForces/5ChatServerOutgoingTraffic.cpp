#include <iostream>
using namespace std;

int add,ans;
main(){
	string s;
	while(getline(cin,s)){
		if(s[0]=='+'){
			add++;
		}else
		if(s[0]=='-'){
			add--;
		}else
		ans+=add*(s.size()-s.find(":")-1);
	}
	cout<<ans;
}