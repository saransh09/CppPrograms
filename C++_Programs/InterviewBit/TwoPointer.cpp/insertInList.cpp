#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &A, vector<int> &B) {
    vector<int>::iterator it1 = A.begin();
    vector<int>::iterator it2 = B.begin();
    while (it1!=A.end() && it2!=B.end()) {
        if (*it1 >= *it2) {
            A.insert(it1,*it2);
            it2++;
            it1++;
            // break;
            continue;
        }
        else {
            it1++;
            continue;
        }
    }
    // while (it1!=A.end()) {
    //     it1++;
    // }
    // while(it2!=B.end()) {
    //     A.insert(it1,*it2);
    //     it2++;
    // }
}

int main() {
	vector<int> v1;
	v1.push_back(2);
	v1.push_back(4);
	v1.push_back(6);
	v1.push_back(8);
	v1.push_back(10);
	v1.push_back(14);
	v1.push_back(19);
	vector<int> v2;
	v2.push_back(1);
	v2.push_back(3);
	v2.push_back(5);
	v2.push_back(7);
	v2.push_back(9);
	v2.push_back(11);
	merge(v1,v2);
	// vector<int>::iterator it  = v1.begin();
	// it++;
	// v1.insert(it,2);
	// it++;
	// it++;
	// it++;
	// v1.insert(it,2);
	for (int i = 0 ; i < v1.size() ; i++) {
		cout<<v1[i]<<' ';
	}
	return 0;
}