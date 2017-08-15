#include <bits/stdc++.h>
using namespace std;

// int count(long long int a) {
//     int c = 0;
//     while(a!=0) {
//         c += a%10;
//         a /= 10;
//     }
//     return c;
// }

// int compute_diff(vector<int> zeros, int i, int j) {
//     if (i==j) {
//         return (j-i+1) - (zeros[j]-zeros[i]);
//     }
//     else {
//         return (j-i+1) - (zeros[j]-zeros[i]-1);
//     }
// }

// vector<int> Solution::flip(string A) {
//     int fin_i = -1, fin_j = -1;
//     int sum = INT_MIN;
//     // long long int a = stoi(A);
//     // int c = count(a);
//     vector<int> zeros;
//     int z = 0;
//     while(A[z]!='\0') {
//         if (A[z]=='0') {
//             zeros.push_back(z);
//         }
//         z++;
//     }
//     int i = 0 , j = 0;
//     while(i!=zeros.size()) {
//         while (j!=zeros.size()) {
//             int tempSum = compute_diff(zeros,i,j);
//             if (tempSum > sum) {
//                 sum= tempSum;
//                 fin_i = zeros[i]+1;
//                 fin_j = zeros[j]+1;
//                 j++;
//                 if (j==zeros.size()) {
//                     i++;
//                     j = i;
//                     break;
//                 }
//                 else {
//                     continue;
//                 }
//             }
//             else if (tempSum == sum) {
//                 j++;
//                 if (j==zeros.size()) {
//                     i++;
//                     j = i;
//                     break;
//                 }
//                 else {
//                     continue;
//                 }
//             }
//             else {
//                 i++;
//                 j = i;
//                 break;
//             }
//         }
//     }
//     vector<int> sol;
//     if (fin_i==-1 || fin_j==-1) {
//         return sol;
//     }
//     sol.push_back(fin_i);
//     sol.push_back(fin_j);
//     return sol;
// }

int main() {
    // cout<<(char(1) + char(0));
    // int j = char(1) + char(0);
    // cout<<j;
    // cout<<itoa("1");
    return 0;
}
