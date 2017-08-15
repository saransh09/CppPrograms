#include <bits/stdc++.h>
using namespace std;



int main() {
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	vector<int>::iterator it = v.begin();
	for(it ; it != v.end() ; it++) {
		if (*(it)%2==0) {
			vector<int>::iterator temp = it;
			it++;
			v.erase(temp);
			continue;
		}
		it++;
	}
	return 0;
}