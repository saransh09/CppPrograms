#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;
	Node() : left(0), right(0) {}
	Node(int data) : data(data), left(0), right(0) {}
	friend class BTree;
};

class BTree {
public:
	Node *root;
	BTree() : root(0) {}
	Node * newNode(int data) {
		Node *temp = new Node(data);
		return temp;
	}
	int height(Node *curr) {
		if (curr==NULL) {
			return 0;
		}
		else {
			return (max(height(curr->left),height(curr->right)) + 1);
		}
	}
	void printInOrder(Node *root) {
		if (root==NULL) {
			return;
		}
		printInOrder(root->left);
		cout<<root->data<<' ';
		printInOrder(root->right);
	}
	void printPathRecur(Node *node, vector<vector<int> > paths,vector<int> path) {
		if (node==NULL) {
			return;
		}
		path.push_back(node->data);
		if (!node->left && !node->right) {
			paths.push_back(path);
			// path.erase();
			return;
		}
		else {
			printPathRecur(node->left, paths,path);
			printPathRecur(node->right, paths, path);
		}
	}
	vector<vector<int> > printPaths(Node *node) {
		vector<int> path;
		vector<vector<int> > paths;
		printPathRecur(node, paths, path);
		return paths;
	}
	bool printAncestors(Node *root, int target) {
		if (!root) return false;
		if (root->data==target) return true;
		if (printAncestors(root->left,target) || printAncestors(root->right,target)) {
			cout<<root->data<<' ';
			return true;
		}
		return false;
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
	t.root->right = t.newNode(7);
	t.printInOrder(t.root);
	// vector<vector<int> > paths = t.printPaths(t.root);
	// cout<<paths.size();
	// for (int i = 0 ; i < paths.size() ; i++) {
	// 	for (int j = 0 ; j < paths[i].size(); j++) {
	// 		cout<<paths[i][j]<<' ';
	// 	}
	// 	cout<<endl;
	// }
	t.printAncestors(t.root, 6);
	return 0;
}