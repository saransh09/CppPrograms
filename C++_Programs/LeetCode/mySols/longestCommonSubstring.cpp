#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string lSub = "";
        unordered_set<char> t;
        for (int i = 0 ; i < s.length() ;i++) {
            int j = i;
            while (t.find(s[j])==t.end()) {
                t.insert(s[j]);
                j++;
            }
            string temp_str = s.substr(i,j);
            if (temp_str.size() > lSub.size()) {
                lSub = temp_str;
            }
            t.clear();
            cout<<endl<<"i="<<i<<"j"<<j<<temp_str<<endl;
            i = j-1;
        }
        return lSub.size();
    }
};

int main() {
	string s = "abcabcbb";
	Solution Z;
	cout<<Z.lengthOfLongestSubstring(s)<<endl;
	return 0;
}