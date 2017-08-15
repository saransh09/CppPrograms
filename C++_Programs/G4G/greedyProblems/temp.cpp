#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(const string &A) {
    int count = 0;
    for (int i = 0 ; i < A.size() ; i) {
        while(A[i]!=' ' && A[i]!='\0') {
            i++;
            count++;
        }
        if (A[i]=='\0') {
            return count;
        }
        if (A[i]==' ') {
            while(A[i]==' ') {
                i++;
            }
            if (A[i]!='\0') {
                count = 0;
                continue;
            }
            else if (A[i]=='\0'){
                return count;
            }
        }
    }
    return count;
}

int main() {
    string a = "Hello World      ";
    cout<<lengthOfLastWord(a);
    return 0;
}