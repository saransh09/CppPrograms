#include <iostream>
#define ll long long
using namespace std;

int sumCheck1(vector<int> v, int i, int j){
	
}

int sumCheck2(vector<int> v, int i, int j){

}

int main() {
	int n;
	cin>>n;
	vector<int> v;
	ll sum = 0;
	for(int i = 0 ; i < n ; i++){
		int x;
		cin>>x;
		sum += x;
		v.push_back(x);
	}
	if(sum%2==1){
		cout<<"FIRST";
		return 0;
	}
	int j = v.size()-1;
	while(sum%2!=1){
		sum -= v[j];
		j--;
	}
}