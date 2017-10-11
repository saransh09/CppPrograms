#include <bits/stdc++.h>
using namespace std;

bool myCompare(pair<int,int> p1, pair<int,int> p2){
	return p1.first < p2.first;
}

bool lineCheck(int x1, int y1, int x2, int y2, float x, float y){
	if(x1!=x2){
		float t = (float)((y1-y2)/(float)(x1-x2)) * (x - x2) + y2;
		if(y==t) return true;
		else return false;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		vector<pair<int,int> > l1,l2,l3;
		vector<pair<int,int> > v;
		for(int i = 0 ; i < 6 ; i++){
			int x,y;
			cin>>x>>y;
			v.push_back(make_pair(x,y));
			if(i<2) l1.push_back(make_pair(x,y));
			else if(i>=2 && i<4) l2.push_back(make_pair(x,y));
			else if(i>=4) l3.push_back(make_pair(x,y));
		}
		pair<int,int> cp;
		sort(v.begin(),v.end(),myCompare);
		for(int i = 0 ; i < 5 ; i++){
			if((v[i].first == v[i+1].first) && (v[i].second == v[i+1].second)){
				cp.first = v[i].first;
				cp.second = v[i].second;
				break;
			}
		}

	}
	return 0;
}