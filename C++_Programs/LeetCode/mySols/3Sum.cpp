#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	vector<vector<int> >  threeSum(vector<int> & num) {
		vector<vector<int> > sol;
		sort(num.begin(),num.end());
		for (int i = 0 ; i < (int)num.size() ; i++) {
			int target = -num[i];
			int front = i+1;
			int rear = num.size()-1;
			while (front < rear) {
				int sum = num[front] + num[rear];
				if (sum < target) front++;
				else if (target > sum) rear--;
				else {
					vector<int> trip = {num[i],num[front],num[rear]};
					sol.push_back(trip);
					while (front < rear && num[front]==trip[1]) front++;
					while (front < rear && num[rear]==trip[2]) rear--;
				}
			}
			while (i+1<(int)num.size() && num[i+1]==num[i]) i++;
		}
		return sol;
	}
};

int main() {
	vector<int> v = {-1, 0, 1, 2, -1, -4};
	Solution s;
	vector<vector<int> > sol = s.threeSum(v);
	for(int i = 0; i < sol.size() ; i++) {
		cout<<"[ ";
		for (int j = 0 ; j < sol[0].size() ; j++) {
			cout<<sol[i][j]<<' ';
		}
		cout<<"]"<<endl;
	}
	return 0;
}