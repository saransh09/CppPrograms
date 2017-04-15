#include<iostream>
using namespace std;

int main(){
int n;
cin>>n;
long long int pr_arr[n];
for(int i=0;i<n;i++){
    long long int arr[2];
    for(int j=0;j<2;j++)
        cin>>arr[j];
    pr_arr[i] = arr[0]*arr[1];
}
for(int i=0;i<n;i++)
    cout<<pr_arr[i]<<endl;
return 0;
}
