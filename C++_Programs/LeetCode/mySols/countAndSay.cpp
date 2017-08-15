#include <bits/stdc++.h>
// #include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string t = "1";
        if (n==1) return t;
        while (n>1) {
            string temp = "";
            int i = 0;
            while(i<t.size()) {
                char ch = t[i];
                int j = i+1;
                while(j<t.size() && t[j]==ch) {
                    j++;
                }
                int nl = (j-i);
                i = j;
                temp += (to_string(nl));
                temp += ch;
            }
            --n;
            t = temp;
        }
        return t;
    }
};

int main() {
	Solution s;
	cout<<s.countAndSay(5);
	return 0;
}