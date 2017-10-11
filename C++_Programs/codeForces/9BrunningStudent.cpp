#include <bits/stdc++.h>
using namespace std;

float calcDistance(float x, float y, float fx, float fy){
	return (float)sqrt(pow(x-fx,2)+pow(y-fy,2));
}

int main() {
	int n,vb,vs;
	cin>>n>>vb>>vs;
	vector<float> stops;
	for(int i = 0 ; i < n ; i++){
		int x;
		cin>>x;
		stops.push_back(x);
	}
	float fx,fy;
	cin>>fx>>fy;
	float x = 0;
	float y = 0;
	float minTime = INT_MAX;
	int optBusStop = -1;
	for(int i = 1 ; i < n ; i++){
		x = stops[i];
		if(x==fx && y==fy){}
		float t1 = (float)x/(float)vb;
		float t2 = (float)calcDistance(x,y,fx,fy)/(float)vs;
		float t = t1 + t2;
		if(t<=minTime){
			optBusStop = i+1;
			minTime = t;
		}
	}
	cout<<optBusStop<<endl;
	return 0;
}