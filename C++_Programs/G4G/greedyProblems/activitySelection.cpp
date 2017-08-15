#include <bits/stdc++.h>
using namespace std;

// void printMaxActivities(vector<int> s, vector<int> f) {
// 	cout<<"The following activities were selected : ";
// 	int i = 0;
// 	cout<<i<<' '; // The first activity is automatically selected
// 	for (int j = 1 ; j < s.size() ; j++) {
// 		if (s[j]>=f[i]) {
// 			cout<<j<<' ';
// 			i = j;
// 		}
// 	}
// }

void printV(vector<pair<int,int> > v) {
	for (int i = 0 ; i < v.size() ; i++) {
		cout<<'('<<v[i].first<<','<<v[i].second<<") ";
	}
	cout<<endl;
}
bool comparePairs(pair<int,int> p1, pair<int,int> p2) {
	return (p1.second < p2.second);
}
void displayMaximumActivites(vector<pair<int,int> > v) {
	int prev = 0;
	cout<<"("<<v[prev].first<<","<<v[prev].second<<") ";
	for (int i = 1 ; i < v.size() ; i++) {
		if (v[i].first > v[prev].second) {
			cout<<"("<<v[i].first<<","<<v[i].second<<") ";
			prev = i;
		}
	}
	cout<<endl;
}

int main() {
	// vector<int> s;
	// s.push_back(1);
	// s.push_back(3);
	// s.push_back(0);
	// s.push_back(5);
	// s.push_back(8);
	// s.push_back(5);
	// vector<int> f;
	// f.push_back(2);
	// f.push_back(4);
	// f.push_back(6);
	// f.push_back(7);
	// f.push_back(9);
	// f.push_back(9);
	// printMaxActivities(s,f);
	int arr[]={5, 0, 8, 3, 5, 1};
    int arr2[]={9, 6, 9, 4, 7, 2};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector< pair<int,int> > v;
    for(int i=0;i<n;i++) {
    v.push_back(make_pair(arr[i],arr2[i]));
    }
    cout<<"Before sorting:"<<endl;
    printV(v);
    //Sorting in Descending order
    sort(v.begin(),v.end(),comparePairs);
    cout<<"After sorting:"<<endl;
    printV(v);
    cout<<"Maximum Activies:"<<endl;
    displayMaximumActivites(v);
	return 0;
}