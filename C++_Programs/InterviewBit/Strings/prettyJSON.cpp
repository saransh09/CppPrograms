#include <bits/stdc++.h>
using namespace std;

string prettyJSON(string A) {
    int len = A.size();
    vector<string> v;
    int tabCount = 0;
    string s;
    for (int i = 0 ; i < len ; i++) {
        if (A[i]=='{' || A[i]=='[') {
            int temp = tabCount;
            while (temp > 0) {
                s += '\t';
                temp--;
            }
            if (A[i]=='{') {
                s += '{';
            }
            else if (A[i]=='[') {
                s += '[';
            }
            s += '\n';
            tabCount++;
        }
        else if (A[i]=='}' || A[i]==']') {
            int temp = tabCount;
            while (temp > 0) {
                s += '\t';
                temp--;
            }
            if (A[i]=='}') {
                s += '}';
            }
            else if (A[i]==']') {
                s += ']';
            }
            s += '\n';
            tabCount--;
        }
        else if (A[i]==',') {
            s += ',';
            s += '\n';
        }
        else if (A[i]==' ') {

        }
        else if (A[i]==':') {
            if (A[i+1]!='{' && A[i+1]!='[') {
                s += ':';
            }
            else {
                s += ':';
                s += '\n';
            }
        }
        else {
            if (i==0) {
                s += A[i];
            }
            else {
                if (s.front()=='\n') {
                    int temp = tabCount;
                    while (temp > 0) {
                        s += '\t';
                        temp--;
                    }
                    s += A[i];
                }
                else {
                    s += A[i];
                }
            }
        }
    }
    vector<string> sol;
    sol.push_back(s);
    return s;
}

int main() {
    A : "{"id":100,"firstName":"Jack","lastName":"Jones","age":12}";
    return 0;
}