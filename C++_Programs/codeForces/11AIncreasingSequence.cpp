#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n,d;
	cin>>n>>d;
	ll prev = INT_MIN;
	ll count = 0;
	for(ll i = 0 ; i < n ; i++){
		ll next;
		cin>>next;
		if(next > prev){
			prev = next;
			continue;
		}
		else{
			while(next<=prev){
				next += d;
				count++;
			}
			prev = next;
			continue;
		}
	}
	cout<<count;
	return 0;
}