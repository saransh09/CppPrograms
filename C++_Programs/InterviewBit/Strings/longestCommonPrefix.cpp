#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &A) {
    string prefix;
    int i;
    int n = A.size()-1;
    for (int i = 0 ; i < A[0].length() ; i++) {
        char ch = A[0][i];
        bool s = true;
        int j = 0;
        while(j <= n) {
            s = s & (ch==A[j][i]);
            j++;
            if (i==3) {
            	cout<<s<<' ';
            }
        }
        if (s==true) {
            prefix += ch;
        }
        else if (s==false) {
            return prefix;
        }
    }
    return prefix;
}

int main() {
	vector<string> A;
	A.push_back("abcdefgh");
	A.push_back("abcefgh");
	string a = longestCommonPrefix(A);
	cout<<a;
	return 0;
}