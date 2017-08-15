#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	struct Pair {
		int start;
		int end;
	};
	vector<int> lszero(vector<int> & A) {
		unordered_map<int,Pair> m;
		int sum = 0;
		for (int i=0 ; i < (int)A.size() ; i++) {
			sum += A[i];
			if (m.find(sum)!=m.end()) m[sum].end = i;
			else {
				m[sum].start = i;
				m[sum].end = -1;
			}
		}
		int min = A.size() , max = 0;
		auto it = m.begin();
		while (it != m.end()) {
			if (it -> first == 0) {
				if (it -> second.end != -1) {
					max = it -> second.end;
				}
				else {
					max = it -> second.start;
				}
				min = -1;
			}
			else if (it -> second.end != -1) {
				if ((max-min) < (it -> second.end - it -> second.start)) {
					max = it -> second.end;
					min = it -> second.start;
				}
				else if(((max-min) == (it->second.end-it->second.start)) &&
                    min > it->second.start){
	                max = it->second.end;
	                min = it->second.start;
            	}
			}
			it++;
		}
		vector<int> sol;
		for (int i = min + 1 ; i <= max ; i++ ) sol.push_back(A[i]);

		return sol;
	}
};


int main() {
	vector<int> v = {1,2,-2,-4,4,6,-6,8,9,8,9,-8,-18,-8};
	Solution s;
	vector<int> sol = s.lszero(v);
	for (int i=0 ; i < (int)sol.size() ; i++) cout<<sol[i]<<' ';
	cout<<endl;
	return 0;
}