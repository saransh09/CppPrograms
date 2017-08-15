#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(0), right(0) {}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode *A) {
			vector<int> sol;
		vector<TreeNode *> temp;
		TreeNode * curr = A;
		temp.push_back(curr);
		while(!temp.empty()) {
			if (!curr) curr = temp.front();
			while(curr -> left) {
				temp.push_back(curr -> left);
				curr = curr -> left;
			}
			curr = temp.front();
			int val = curr -> val;
			sol.push_back(val);
			curr = curr -> right;
			temp.pop_back();
		}
	}
};

int main() {

	return 0;
}