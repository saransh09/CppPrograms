#include <bits/stdc++.h>
using namespace std;

void volHelper(vector<int> & v, int i, int l, int h,int currans,int & ans) {
	if(i==(int)v.size()) {
		if ((currans > 0 && currans < h) && ans < currans) ans = currans; 
	}
	if (currans > h || currans < 0) return;
	volHelper(v,i+1,l,h,currans+v[i],ans);
	volHelper(v,i+1,l,h,currans-v[i],ans);
}

int vol(vector<int> & v, int l, int h) {
	int ans = -1;
	volHelper(v,0,l,h,0,ans);
	return ans;
}

int main() {
	vector<int> v1= {1,2,3,1,4,2,1,0,0,1,2,1};
	cout<<vol(v1,0,5);
	return 0;
}