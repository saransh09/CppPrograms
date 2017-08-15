#include<bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
	int largestAreaHistogram(vector<int> & height) {
		int maxArea = 0;
		vector<int> index;
		for (int i = 0; i < height.size(); i++) {
			while(index.size() > 0 && height[index.back()] >= height[i]) {
				int h = height[index.back()];
				index.pop_back();
				int sidx = index.size() > 0 ? index.back() : -1;
				if (h * (i - sidx - 1) > maxArea) {
					maxArea = h*(i - sidx - 1);
				}
				index.push_back(i);			
			}			
		}
		return maxArea;
	}
};

int main() {
	return 0;
}
