#include <bits/stdc++.h>
using namespace std;

void printSet(unordered_set<int> s) {
	unordered_set<int>::iterator it = s.begin();
	while (it!=s.end()) {
		cout<<*it<<' ';
		it++;
	}
	cout<<endl;
}

bool isValidSudoku(const vector<string> &A) {
    vector<unordered_set<int> > rows(A.size());
    vector<unordered_set<int> > columns(A.size());
    vector<unordered_set<int> > cube(A.size());
    for (int i = 0 ; i < 9 ; i++) {
    	rows[i].clear();
    	columns.clear();
    	cube.clear();
    }
    for (int i = 0 ;i < A.size() ; i++) {
        for (int j = 0 ; j < A.size() ; j++) {
            if (A[i][j]!='.') {

                if (rows[i].find(A[i][j])!=rows[i].end()) {
					cout<<"COND1 i = "<<i<<"  j = "<<j<<endl;
					printSet(rows[i]);
                	return false;
                }
                else {
                	rows[i].insert(A[i][j]);
                	cout<<"The set for rows i = "<<i<<endl;
                	printSet(rows[i]);
                }
                
                if (columns[j].find(A[i][j])!=columns[j].end()) {
                	cout<<"COND2 i = "<<i<<"  j = "<<j<<endl;
                	printSet(columns[i]);
                	return false;
                }
                else {
                	columns[j].insert(A[i][j]);
                	cout<<"The set for column  j = "<<j<<endl;
                	printSet(columns[i]);
                }
                
                if (cube[(i/3)+(j/3)].find(A[i][j])!=cube[(i/3)+(j/3)].end()) {
                	cout<<"COND3  i = "<<i<<"  j = "<<j<<endl;
                	printSet(cube[(i/3)+(j/3)]);
                	return false;
                }
                else {
                	cube[(i/3)+(j/3)].insert(A[i][j]);
                	cout<<"cube "<<i/3 + j/3<<endl;
                	printSet(cube[(i/3)+(j/3)]);
                }
            }
            else {
            	continue;
            }
        }
    }
    return true;
}

int main() {
	vector<string> A = {"..5.....6", "....14...", ".........", ".....92..", "5....2...", ".......3.", "...54....", "3.....42.", "...27.6.." };
	for (int i = 0 ; i < 9 ; i++) {
		for (int j = 0 ; j < 9 ; j++) {
			cout<<A[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<isValidSudoku(A)<<endl;
	return 0;
}