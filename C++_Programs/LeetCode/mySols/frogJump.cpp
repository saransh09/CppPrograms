#include <bits/stdc++.h>
using namespace std;

class Sol{
	unordered_map<int,int> s;
public:
	bool canCross(vector<int> & stones) {
		if (stones.size()<2) return true;
		if (stones[1]!=1) return false;
		s[0]=0;
		for (int i=1; i < stones.size() ; i++) {
			s[stones[i]] = i;
			if (stones[i] - stones[i-1] > i) return false;
		}
		return helper(stones,1,1);
	}
	bool helper(vector<int> & stones, int step, int pos) {
		if (pos==stones.size()-1) return true;
		if (pos > stones.size()) return false;
		if (s.find(stones[pos]+step+1)!=s.end())
			if(helper)
	}
};

class Solution {
    bool helper (vector<int>& stones, int step, int pos) {
        if (pos==stones.size()-1) return true;
        if (pos>stones.size()) return false;
        
        if (s.find(stones[pos]+step+1)!=s.end())  
            if(helper(stones,step+1,s[stones[pos]+step+1])) return true;
        
        if (s.find(stones[pos]+step)!=s.end()) 
            if(helper(stones,step,s[stones[pos]+step])) return true;
        
        if (step>1 && s.find(stones[pos]+step-1)!=s.end()) 
            if(helper(stones,step-1,s[stones[pos]+step-1])) return true;
        
        return false;
    }
};

int main() {
	// double a = 2 << 30;
	cout<<a;

	return 0;
}