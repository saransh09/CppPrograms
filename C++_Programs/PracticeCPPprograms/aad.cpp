#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string A) {
    stack<char> path;
    string sol;
    if (A.size()==0) {
        return sol;
    }
    sol += '/';
    if (A.size()==1) {
        return sol;
    }
    for (int i = 1 ; i < A.size() ; i++) {
        if (97<=int(A[i]) && int(A[i])<=122) {
            cout<<"asd"<<' ';
            path.push(A[i]);
            continue;
        }
        else {
            if (A[i]=='/') {
                continue;
            } 
            if (A[i]=='.') {
                if (i+1<A.size() && A[i+1]=='.') {
                    ++i;
                    path.pop();
                    continue;
                }
                else {
                    continue;
                }
            }
        }
    }
    while(!path.empty()) {
        char ch = path.top();
        path.pop();
        sol += ch;
        if (!path.empty()) {
            sol += '/';
        }
        else {
            return sol;
        }
    }
}


int main() {
	string A = "/a/./b/../../c/";
	string sol = simplifyPath(A);
	cout<<sol;
	return 0;
}