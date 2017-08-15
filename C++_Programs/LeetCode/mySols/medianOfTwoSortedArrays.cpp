#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size();
        int n2 = b.size();
        if ((n1+n2)%2==1) {
            int i = 0, j = 0;
            int count = 0;
            while(count<(n1+n2)/2 && i<n1 && j<n2) {
                if (a[i]<b[j]) {
                    i++;
                }
                else {
                    j++;
                }
                count++;
            }
            while(count<(n1+n2)/2 && i<n1) {
                i++;
                count++;
            }
            while(count<(n1+n2)/2 && j<n2) {
                j++;
                count++;
            }
            if (i==n1) return b[j];
            if (j==n2) return a[i];
            return min(a[i],b[j]);
        }
        else {
            int i = 0, j = 0;
            int count = 0;
            while(count<(n1+n2)/2 && i<n1 && j<n2) {
                if (a[i]<b[j]) {
                    i++;
                }
                else {
                    j++;
                }
                count++;
            }
            while(count<(n1+n2)/2 && i<n1) {
                i++;
                count++;
            }
            while(count<(n1+n2)/2 && j<n2) {
                j++;
                count++;
            }
            if (i==n1) {
                if (j==0) {
                    cout<<endl<<b[j]<<' '<<a[n1-1];
                    return (float(b[j]+a[n1-1])/2);
                }
                return float(b[j]+b[j-1])/2;
            }
            if (j==n2) {
                if (i==0) {
                    return (float(a[i]+b[n2-1])/2);
                }
                return float(a[i]+a[i-1])/2;
            }
            return float(a[i]+b[j])/2;
        }
    }
};

int main() {
    vector<int> v1 = {1,2};
    vector<int> v2 = {3,4};
    Solution s;
    cout<<endl<<s.findMedianSortedArrays(v1,v2)<<endl;
    return 0;
}