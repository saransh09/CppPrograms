#include <bits/stdc++.h>
using namespace std;

class Node {
	int data;
	Node *left;
	Node *right;
public:
	Node() : left(0), right(0) {}
	Node(int d) : data(d), left(0), right(0) {}
public:
	Node * newNode(int d) {
		Node * temp = new Node(d);
		return temp;
	}
	friend class Tree;
};

class Tree {
	Node * root;
public:
	Tree() : root(0) {}
	Tree(int d) {
		root = newNode(d);
	}
	int identicalTrees(Node *a, Node *b) {
		if (a==NULL && b==NULL) {
			return 1;
		}
		if (a!=NULL && b!=NULL) {
			return 
			(
				a->data == b->data && identicalTrees(a->left,b->left) && identicalTrees(a->right,b->right)
			);
		}
	return 0;
	}
	friend class Node;
};

int main() {
	// Node t1
	return 0;
}