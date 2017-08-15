#include <bits/stdc++.h>
using namespace std;

// struct Interval{
// 	int start;
// 	int end;
// 	Interval() : start(0), end(0) {}
// 	Interval(int s, int e) : start(s), end(e) {}
// };

// void insertAll(set<int> & S, Interval a) {
// 	int s =  (a.start > a.end) ? a.start : a.end ;
// 	int e = (a.start > a.end) ? a.end : a.start;
//     for (int i = s ; i <= e ; i++) {
//         S.insert(i);
//     }
// }

// vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
//     set<int> S;
//     vector<Interval> sol;
//     for (int i = 0 ; i < intervals.size() ; i++) {
//         insertAll(S,intervals[i]);
//     }
//     insertAll(S,newInterval);
//     set<int>::iterator it = S.begin();
//     int t = *it;
//     ++it;
//     // cout<<
//     while(it!=S.end()) {
//         int y = t;
//         while(*it==(y+1)) {
//             y = *it;
//             it++;
//         }
//         Interval itv = Interval(t,y);
//         sol.push_back(itv);
//         t = *it;
//         it++;
//     }
//     return intervals;
// }

int main() {
	// Interval it = Interval(1,2);
	// Interval it1 = Interval(3,6);
	// vector<Interval> v;
	// v.push_back(it);
	// v.push_back(it1);
	// vector<Interval> sol = insert(v,Interval(10,8));
	// for (int i = 0 ; i < sol.size() ; i++) {
	// 	cout<<'('<<sol[i].start<<','<<sol[i].end<<')'<<' ';
	// }
	string s;
	s += '\n';
	cout<<s;
	cout<<'1';
	return 0;
}