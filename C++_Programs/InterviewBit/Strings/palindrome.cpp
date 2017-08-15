#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string A) {
    int i = 0;
    int j = A.size()-1;
    // cout<<j<<endl;
    while(i<j) {
        if(int(A[i])<65 && int(A[i])>122) {
            cout<<'a';
            i++;
            // continue;
        }
        if (int(A[i])>90 && A[i]<97) {
            cout<<'b';
            i++;
            // continue;
        }
        if(int(A[j])<65 && int(A[j])>122) {
            cout<<'c';
            j--;
            // continue;
        }
        if (int(A[j])>90 && int(A[j])<97) {
            cout<<'d';
            j--;
            // continue;
        }
        if(A[i]==' ') {
            i++;
            continue;
        }
        if(A[j]==' ') {
            j--;
            continue;
        }
        if (int(A[i])<97) {
            if (int(A[i])==int(A[j]) || (int(A[i])+32)==int(A[j])) {
                cout<<'e';
                i++;
                j--;
                continue;
            }
            else {
                cout<<'f';
                return 0;
            }
        }
        else {
            if (int(A[i])==int(A[j]) || (int(A[i])-32)==int(A[j])) {
                cout<<'g';
                i++;
                j--;
                continue;
            }
            else {
                cout<<'h';
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    string a = "A man, a plan, a canal: Panama";
    cout<<isPalindrome(a);
    // cout<<int(a[0])+32;
}