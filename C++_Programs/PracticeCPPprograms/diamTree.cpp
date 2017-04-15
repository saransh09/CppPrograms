#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class BTNode {
	int data;
	BTNode *left, *right;
public:
	BTNode() : left(0), right(0) {}
	BTNode(int data) : data(data), left(0), right(0) {}
	friend class binaryTree;
};

class binaryTree {
public:
	BTNode *root;
public:
	binaryTree() : root(0) {}
	void createTree() {
		if (root) {
			throw "Tree already exists";
		}
		createTreeHelper(root);
	}
public:
	static BTNode * createTreeHelper(BTNode *) {
		int el;
		cout<<"Enter the data for the node : ";
		cin>>el;
		BTNode * curr = new BTNode(el);
		char ch;
		cout<<"Does "<<el<<" contain left child (y/n) : ";
		cin>>ch;
		if (ch == 'y' || ch == 'Y') {

		}
		else {
			curr -> left = createTreeHelper(curr);
		}
		cout<<"Does "<<el<<" contain right child (y/n) : ";
		cin>>ch;
		if (ch == 'y' || ch == 'Y') {

		}
		else {
			curr -> right = createTreeHelper(curr);
		}
		return curr;
	}
	int max(int a, int b) {
		return ((a >= b) ? a : b);
	}
	int height(BTNode * root) {
		if(root==NULL) {
			return 0;
		}
		return 1 + max(height(root->left),height(root->right));
	}
	int diameter(BTNode * T) {
		if (T == NULL) {
			return 0;
		}
		// Calculate the height of the left and right subtree
		int lheight = height(T->left);
		int rheight = height(T->right);
		// Calculate subsequently the diamter of the left and right subtree
		int ldiameter = diameter(T->left);
		int rdiameter = diameter(T->right);
		// return the max
		return max(lheight + rheight + 1, max(ldiameter, rdiameter));
	}

};

int main() {
	binaryTree T;
	T.createTree();
	cout<<endl<<endl<<endl<<T.diameter(T.root);
	return 0;
}