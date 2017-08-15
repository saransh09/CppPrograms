#include <bits/stdc++.h>
using namespace std;

class BTNode {
public:
	int data;
	BTNode *left, *right;
	BTNode() : left(0), right(0) {}
	BTNode(int x) : data(x), left(0), right(0) {}
	friend class BTree;
};
class BTree {
public:
	BTNode *root;
	BTree() : root(0) {}
	BTNode * newNode(int x) {
		BTNode * new_node = new BTNode(x);
		return new_node;
	}
	void printInorder(BTNode *root) {
		if (root==NULL) {
			return;
		}
		printInorder(root->left);
		cout<<root->data<<' ';
		printInorder(root->right);
	}
	int height(BTNode *root) {
		if (root==NULL) {
			return 0;
		}
		else return (max(height(root->left), height(root->right)) + 1); 
	}
	void mirrorTree(BTNode *curr) {
		if (curr==NULL) {
			return;
		}

		BTNode *temp;
		mirrorTree(curr->left);
		mirrorTree(curr->right);
		temp = curr->left;
		curr->left = curr->right;
		curr->right = temp;
	}
	void printLevelOrder(BTNode *curr) {
		queue<BTNode *> Q;
		Q.push(curr);
		while(!Q.empty()) {
			BTNode *temp = Q.front();
			cout<<temp->data<<' ';
			Q.pop();
			if(temp->left!=NULL) {
				Q.push(temp->left);
			}
			if(temp->right!=NULL) {
				Q.push(temp->right);
			}
		}

	}
	int diameterNaive(BTNode *head) {
		if (head=NULL) {
			return 0;
		}
		int lheight = height(head->left);
		int rheight = height(head->right);
		int ldiameter = diameterNaive(head->left);
		int rdiameter = diameterNaive(head->right);
		return max(lheight + rheight + 1, max (ldiameter,rdiameter));
	}
	// int diameter(BTNode *head, int *h) {
	// 	int lh = 0, rh = 0;
	// 	int ld = 0, rd = 0;
	// 	if (head == NULL) {
	// 		*h = 0;
	// 		return 0;
	// 	}
	// 	ld = diameter(head->left, &lh);
	// 	rd = diameter(head->right, &rh);
	// 	*h = max(lh, rh) + 1;
	// 	return max(lh + rh + 1, max(ld, rd));
	// }
	int diameterOptimized(BTNode *head, int *h) {
		int lh = 0, rh = 0;
		int ld = 0, rd = 0;
		if (head==NULL) {
			*h = 0;
			return 0;
		}
		ld = diameterOptimized(head->left,&lh);
		rd = diameterOptimized(head->right,&rh);
		*h = max(lh,rh) + 1;
		return max(lh + rh + 1, max(ld,rd));
	}
	int countLeafNode(BTNode *head) {
		if (head==0) {
			return 0;
		}
		if (head->left==NULL && head->right==NULL) {
			return 1;
		}
		else {
			return countLeafNode(head->left) + countLeafNode(head->right);
		}
	}
	// bool isBalanced(BTNode *head) {
	// 	int lh,rh;
	// 	if (head==NULL) {
	// 		return 1;
	// 	}
	// 	lh = height(head->left);
	// 	rh = height(head->right);
	// 	if (abs(lh-rh)<=1 && isBalanced(head->left) && isBalanced(head->right)) {
	// 		return 1;
	// 	}
	// 	else {
	// 		return 0;
	// 	}
	// }  										// This is the O(n^2) implementation
	// bool isBalancedOpt(BTNode *head, int *h) {
	// 	int lh = 0, rh = 0;
	// 	int l = 0 , r = 0;
	// 	if (head==NULL) {
	// 		*h = 0;
	// 		return 1;
	// 	}
	// 	l = isBalancedOpt(head->left,&lh);
	// 	r = isBalancedOpt(head->right,&rh);
	// 	*h = ((lh>rh) ? lh : rh) + 1 ;
	// 	if (abs(lh-rh) >= 2) {
	// 		return 0;
	// 	}
	// 	else return l && r;
	// }
	// int diameter(BTNode * head) {
	// 	if (head==NULL) {
	// 		return 0;
	// 	}
	// 	int lheight = height(head->left);
	// 	int rheight = height(head->right);
	// 	int ldiameter = diameter(head->left);
	// 	int rdiameter = diameter(head->right);
	// 	return max(lheight + rheight + 1, max(ldiameter, rdiameter));
	// }
	// int diameterOptimized(BTNode *head, int *h) {
	// 	int lh = 0, rh = 0, ld = 0, rd = 0;
	// 	if (head==NULL) {
	// 		*h = 0;
	// 		return 0;
	// 	}
	// 	ld = diameterOptimized(head->left, &lh);
	// 	rd = diameterOptimized(head->right, &rh);
	// 	*h = max(lh,rh) + 1;
	// 	return max(lh + rh + 1, max(ld,rd));
	// }
	bool isBalancedNaive(BTNode *root) {
		int lh, rh;
		if (!root) {
			return 1;
		}
		lh = height(root->left);
		rh = height(root->right);
		if (abs(lh - rh) <= 1 && isBalancedNaive(root->left) && isBalancedNaive(root->right)) {
			return 1;
		}
		return 0;
	}
	bool isBalancedOptimized(BTNode *root, int *h) {
		int lh = 0, rh = 0, l = 0, r = 0;
		if (!root) {
			*h = 0;
			return 1;
		}
		l = isBalancedOptimized(root->left, &lh);
		r = isBalancedOptimized(root->right, &rh);
		*h = (lh > rh ? lh : rh) + 1;
		if (abs(lh - rh) >= 2) {
			return 0;
		}
		else return l&&r;
	}
	int sizeTree(BTNode *root) {
		if (!root) {
			return 0;
		}
		int ls = sizeTree(root->left);
		int rs = sizeTree(root->right);
		return (ls + rs+ 1);
	}
	bool hasPathSum(BTNode *node, int sum) {
		if (!node) {
			return (sum==0);
		}
		else {
			bool ans = 0;
			int subSum = sum - node->data;
			if (subSum == 0 && node->left == NULL && node->right == NULL) return 1;
			if (node->left) ans = ans || hasPathSum(node->left, subSum);
			if (node->right) ans = ans || hasPathSum(node->right, subSum);
			return ans;
		}
	}
	void increment(BTNode *node, int diff) {
		if (node -> left) {
			node->left->data += diff;
			increment(node->left, diff);
		}
		else if (node->right) {
			node->right->data += diff;
			increment(node->right, diff);
		}
	}
	void converTree(BTNode *node) {
		int ld = 0, rd = 0, diff;
		if (!node || !node->left || !node->right) return;
		else {
			converTree(root->left);
			converTree(root->right);
			if (node->left) {
				ld = node->left->data;
			}
			if (node->right) {
				rd = node->right->data;
			}
			diff = ld + rd - node->data;
		}
		if (diff > 0) {
			node -> data = node -> data + diff;
		}
		if (diff < 0) {
			node -> data = node -> data - diff;
		}
	}
	int search (vector<char> in, int inStrt, int inEnd, int d) {
		int i = 0;
		for (i = inStrt; i <= inEnd ; i++) {
			if (in[i]==d) {
				return i;
			}
		}
	}
	BTNode * buildTree(vector<char> in, vector<char> pre, int inStrt, int inEnd) {
		static int preIndex = 0;
		if (inStrt > inEnd) {
			return NULL;
		}
		BTNode * tNode = newNode(pre[preIndex++]);
		if (inStrt == inEnd) return tNode;
		int inIndex = search(in, inStrt, inEnd, tNode->data);
		tNode->left = buildTree(in, pre, inStrt, inIndex-1);
 		tNode->right = buildTree(in, pre, inIndex+1, inEnd);
		return tNode;
	}
	void printPathHelper(BTNode *root, vector<vector<BTNode *> > path, int pathLen) {
		if (root==NULL) {
			return;
		}
		
	}
	void printPaths(BTNode *root) {
		vector<vector<BTNode *> > path;
		printPathHelper(root, path, 0);
	}
};

int main() {
	BTree t;
	t.root = t.newNode(1);
	t.root->left = t.newNode(2);
	t.root->right = t.newNode(3);
	t.root->left->left = t.newNode(4);
	t.root->left->right = t.newNode(5);
	t.root->right->left = t.newNode(6);
	t.root->right->right = t.newNode(7);
	cout<<t.height(t.root);
	cout<<endl;
	t.printInorder(t.root);
	cout<<endl;
	t.printLevelOrder(t.root);
	t.mirrorTree(t.root);
	cout<<endl;
	t.printInorder(t.root);
	cout<<endl;
	int h = 0;
	cout<<t.diameterOptimized(t.root, &h);
	cout<<endl;
	cout<<t.countLeafNode(t.root);
	cout<<endl;
	cout<<t.isBalancedNaive(t.root)<<endl;
	h = 0;
	cout<<t.isBalancedOptimized(t.root, &h)<<endl;
	cout<<"The size of the tree is : "<<t.sizeTree(t.root);

	return 0;
}