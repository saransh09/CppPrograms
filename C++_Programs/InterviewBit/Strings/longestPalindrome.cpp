#include <bits/stdc++.h>
using namespace std;

string longestPalindromeDP(string A) {
    int n = A.length();
    bool table[n][n];
    memset(table, 0, sizeof(table));

    int maxLength = 1;
    for (int i=0;i<n;i++) {
        table[i][i] = true;
    }
    int start = 0;
    for (int i = 0 ; i < n-1 ; i++) {
        if (A[i]==A[i+1]) {
            table[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }
    for (int k=3 ; k<=n; k++) {
        for (int i=0 ; i < n-k+1 ; i++) {
            int j = i+k-1;
            if (table[i+1][j-1] && A[i]==A[j]) {
                table[i][j] = true;
                if (k>maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    string sol;
    for (int i = start ; i <= maxLength+1 ; i++) {
        sol += A[i];
    }
    return sol;
}

string longestPalindromeDPoptimized(string A) {
    int maxLength = 1;
    int start = 0;
    int len = A.length();
    int low, high;
    for (int i=0 ; i<len ; i++) {
            
    }
}

int main() {
    string s = "atrpqssqprds";
    cout<<longestPalindromeDP(s);
    return 0;
}