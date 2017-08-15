#include <bits/stdc++.h>
using namespace std;

void swap(char & a, char & b) {
    char temp = a;
    a = b;
    b = temp;
    return;
}

int makeChange(string & s) {
    unordered_set<char> us;
    int j = s.size()-1;
    int i = 0;
    us.insert(s[i]);
    i++;
    while(i<j) {
        if(us.find(s[i])!=us.end()){
            while(us.find(s[j])!=us.end()) j--;
            swap(s[i],s[j]);
            j--;
            cout<<"i = "<<i<<endl;
            cout<<"j = "<<j<<endl;
        }
        else {
            us.insert(s[i]);
            i++;
            cout<<"i = "<<i<<endl;
            cout<<"j = "<<j<<endl;
        }
    }
    return j;
}

int main() {
	int t;
	cin>>t;
	for(int i = 0 ; i < t ; i++) {
	    string s;
	    cin>>s;
	    int j = makeChange(s);
	    cout<<s.substr(0,j);
	}
	return 0;
}