#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;


void printVectorHelper(const vector<vector<int> > V) {
	for (int i = 0 ; i < V.size() ; i++) {
		for (int j = 0 ; j< V[0].size() ; j++) {
			cout<<V[i][j]<<' ';
		}
		cout<<endl;
	}
	return;
}

void setZeroes(vector<vector<int> > &A) {
    unordered_set<int> mySet;
    for (int i = 0 ; i < A.size() ; i++) {
        for (int j = 0 ; j < A[0].size() ; j++) {
            if (A[i][j]==0) {
                mySet.insert(i);
                mySet.insert(j);
            }
        }
    }
    for (int i = 0 ; i < A.size() ; i++) {
        for (int j = 0 ; j < A[0].size() ; j++) {
            unordered_set<int>::iterator it1 = mySet.find(i);
            unordered_set<int>::iterator it2 = mySet.find(j);
            if (it1!=mySet.end() || it2!=mySet.end()) {
                A[i][j] = 0;
            }
        }
    }
}

int main() {
	vector<vector<int> > V;
	vector<int> v;
	v.push_back(1);
	v.push_back(0);
	v.push_back(1);
	V.push_back(v);
	v.erase(v.begin(),v.end());
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	V.push_back(v);
	V.push_back(v);
	setZeros(V);
	printVectorHelper(V);
	return 0;
}