#include <iostream>
using namespace std;

int main() {
	while(1){
		int c;
		cin>>c;
		if(c==0) break;
		string s;
		cin>>s;
		int l = s.length();
		int temp2 = c;
		for(int curr = 0 ; curr < c ; curr++){
			int counter = 0;
			int temp = curr;
			while(temp<l){
				cout<<s[temp];
				if (counter%2==0) temp += 2*temp2-1;
				else temp += 2*curr + 1;
				counter++;
			}
			temp2--;
		}
		cout<<endl;
	}
	return 0;
}