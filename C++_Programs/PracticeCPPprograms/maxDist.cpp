#include <bits/stdc++.h>
using namespace std;

int maximumGap(const vector<int> &A) {
    int maxDist = 0;
    if (A.size()==2) {
        return 1;
    }
    for (int i = 0 ; i < A.size() ; i++) {
        for (int j = i+maxDist ; j < A.size() ; j++) {
            if (A[j] >= A[i]) {
                if ((j-i) > maxDist) {
                    maxDist = j-i;   
                }
            }
        }
    }
    return maxDist;
}

int main() {
    vector<int> v;
    v.push_back(2);
    
    return 0;
}