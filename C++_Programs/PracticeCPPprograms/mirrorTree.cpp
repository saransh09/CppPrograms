#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;
class Node {
	int data;
	Node *left,*right;
public:
	Node() : left(0), right(0) {}
	Node(int x) : data(x), left(0), right(0) {}
	friend class BinaryTree;
};
class BinaryTree {
	Node *root;
public:
	BinaryTree() : root(0) {}
	int max(int a, int b) {
		return a > b ? a : b ;
	}
	int height(Node *root) {
		if(!root) {
			return 1;
		}
		return 1 + max(height(root->left),height(root->right));
	}
	void mirrorTree(Node *curr) {
		if (curr == NULL) {
			return;
		}
		else{	
			Node *temp;
			mirrorTree(curr->left);
			mirrorTree(curr->right);
			temp  = curr ->left;
			curr -> left = curr -> right;
			curr -> right = temp ;
		}
	}
	
	
};

int main() {

	return 0;
}