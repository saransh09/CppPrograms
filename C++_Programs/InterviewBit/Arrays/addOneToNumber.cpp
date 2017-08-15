#include <bits/stdc++.h>
using namespace std;

int strStr(const string &haystack, const string &needle) {
    for (int i = 0; haystack[i]!='\0' ; i++) {
        if (haystack[i]==needle[0]) {
        	int z = 0;
            for (int j = i; haystack[j]!='\0' ; j++) {
                if(haystack[j]!=needle[z]) {
                	cout<<"ababa";
                    break;
                }
                ++z;
                if (z==needle.size()-1 || needle.size()==1) {
                    return i;
                }
            }
        }
    }
    return -1;
}

int main() {
	string a = "abcdefg";
	string b = "cde";
	cout<<strStr(a,b);
	return 0;
}