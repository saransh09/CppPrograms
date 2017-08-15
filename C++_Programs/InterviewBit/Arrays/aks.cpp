#include <bits/stdc++.h>
#include <vector>
using namespace std;

int checkSame(vector<int> & a, vector<int> & b, int N) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0 ; i < N ; i++) {
        if (a[i]!=b[i]) {
            return 0;
        }
        else {
            return 1;
        }
    }
}

int main() {
	int T;
	cin>>T;
	int N[T];
	vector<int> O;
	for (int i = 0 ; i < T ; i++) {
	    cin>>N[i];
	    vector<int> a,b;
	    for (int j = 0 ; j < N[i] ; j++) {
	        int t;
	        cin>>t;
	        a.push_back(t);
	    }
	    for (int j = 0 ; j < N[i] ; j++) {
	        int t;
	        cin>>t;
	        b.push_back(t);
	    }
	    int o = checkSame(a,b,N[i]);
	    O.push_back(o);
	}
	for (int i = 0 ; i < T ; i++) {
	    cout<<O[i]<<endl;
	}
	return 0;
}