#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length()!=t.length()) return false;
    if (s.length()==0 && t.length()==0) return true;
    if (s.length()==0) return false;
    if (t.length()==0) return false;
    unordered_map<char,int> ms , mt;
    for (int i = 0 ; i < s.length() ; i++) {
    	cout<<"s[i] is "<<s[i]<<" t[i] is "<<t[i]<<endl;;
        if (ms.find(s[i])==ms.end()) {
            ms[s[i]] = 1;
        }
        else {
            ms[s[i]] = ms[s[i]] + 1;
        }
        if (mt.find(t[i])==mt.end()) {
            mt[t[i]] = 1;
        }
        else {
            mt[t[i]] = mt[t[i]] + 1;
        }
    }
    unordered_set<char> set1;
    for (int i = 0 ; i < s.length() ; i++) {
        set1.insert(s[i]);
    }
    auto it = set1.begin();
    while (it!=set1.end()) {
    	if (ms[*it]==mt[*it]) {
    		cout << "value of it is : "<<*it<<endl;
        	cout<<" value of ms[*it] is "<<ms[*it]<<" and the value of mt[*it] is "<<mt[*it]<<endl;
    	}
        if (ms[*it]!=mt[*it]) {
        	cout << "value of it is : "<<*it<<endl;
        	cout<<" value of ms[*it] is "<<ms[*it]<<" and the value of mt[*it] is "<<mt[*it]<<endl;
        	return false;
        }
        it++;
    }
    return true;
}

int main() {
	string s = "aacc";
	string t = "ccac";
	cout<<isAnagram(s,t)<<endl;
	return 0;
}