#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	// Recursive Solution
	bool isMatchRec(const char *s, const char *p) {
		if (!*p) return (!*s);
		if ('*'==*(p+1)) {
			return (isMatchRec(s,p+2) || *s && (*s == *p || '.' == *p) && isMatchRec(s+1,p));
		}
		else {
			if (!*s) return false;
			return (*s==*p || *p=='.') ? isMatchRec(s+1,p+1) : false;
		}
	}
	bool isMatchRec(string s, string p) {
		if (p.empty()) return (s.empty());
		if ('*'==p[1]) return (isMatchRec(s,p.substr(2)) || !s.empty() && (s[0]==p[0] || '.'==p[0]) && isMatchRec(s.substr(1),p));
		else return !s.empty() && (s[0]==p[0] || '.'==p[0]) && isMatchRec(s.substr(1),p.substr(1));
	}
	bool isMatchDP(const char *s, const char *p) {

	}
	bool isMatchDP(string s, string p) {
		int m = s.size() ; int n = p.size();
		vector<vector<bool> > f(m+1, vector<bool>(n+1,false));
		f[0][0] = false;
		for (int i = 1 ; i <= m ; i++) {
			f[i][0] = false;
		}
		for (int j = 1; j <= n; j++) {
			
		}
	}
};

int main() {

	return 0;
}