#include <bits/stdc++.h>
using namespace std;

void reverseWords(string &A) {
    vector<string> v;
    string s;
    s.clear();
    for (int i = 0 ; i < A.size() ;) {
        if (A[i]==' ') {
            while(A[i+1]==' ') {
                i++;   
            }
            v.push_back(s);
            s.clear();
        }
        else {
            s += A[i];
            i++;
        }
    }
    reverse(v.begin(),v.end());
    vector<string>::iterator it = v.begin();
    int n = v.size();
    string sol;
    for (it; it<(it)+n ; it++) {
        sol += *it;
        sol += ' ';
    }
    A = sol;
}

int main() {
	string s = "What a beautiful day";
	reverseWords(s);
	cout<<s;
	return 0;
}