#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int trapDP(vector<int> & h) {
		if (h.size()<2) return 0;
		int ans = 0;
		int size = h.size();
		vector<int> lmax(size), rmax(size);
		lmax[0] = h[0];
		rmax[size-1] = h[size-1];
		for (int i=1 ; i<size ; i++) {
			lmax[i] = max(h[i],lmax[i-1]);
		}
		for (int j=size-2 ; j >= 0 ; j--) {
			rmax[j] = max(rmax[j+1],h[j]);
		}
		for (int i = 0 ; i < size - 1; i++) {
			ans += min(lmax[i],rmax[i]) - h[i];
		}
		return ans;
	}
	// int trapStack(vector<int> & h) {
	// 	int ans; int current = 0;
	// 	stack<int> s;
	// 	while (current < h.size()) {
	// 		while(!s.empty() && h[current] > h[s.top()]) {
	// 			int top = s.top();
	// 			s.pop();
	// 			if (s.empty()) break;
	// 			int distance = current - s.top() - 1;
	// 			int bounded_height = min(h[])
	// 		}
	// 	}
	// }
	int trap(vector<int>& height)
	{
	    int left = 0, right = height.size() - 1;
	    int ans = 0;
	    int left_max = 0, right_max = 0;
	    while (left < right) {
	        if (height[left] < height[right]) {
	            height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
	            ++left;
	        }
	        else {
	            height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
	            --right;
	        }
	    }
	    return ans;
	}
};

int main() {
	vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
	Solution s;
	cout<<s.trap(v);
	return 0;
}