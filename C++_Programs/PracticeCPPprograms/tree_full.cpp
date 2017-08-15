#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;
	Node() : left(0), right(0) {}
	Node(int data) : data(data), left(0), right(0) {}
	friend class Btree;
};

class Btree {
public:
	Node *root;
	Btree() : root(0) {}
	Node * newNode(int data) {
		Node * new_node = new Node(data);
		return new_node;
	}
	int height(Node *head) {
		if (head==NULL) {
			return 0;
		}
		else {
			return max(height(head->left),height(head->right)) + 1;
		}
	}
	void InorderTraversal(Node *head) {
		if (head==NULL) {
			return;
		}
		InorderTraversal(head->left);
		cout<<head->data<<' ';
		InorderTraversal(head->right);
	}
	void mirrorTree(Node *head) {
		if (head==NULL) {
			return;
		}
		mirrorTree(head->left);
		mirrorTree(head->right);
		Node *temp = head->left;
		head->left = head->right;
		head->right = temp;
	}
	void printLevelOrder(Node *head) {
		queue<Node *> Q;
		Q.push(head);
		while(!Q.empty()) {
			Node * temp = Q.front();
			Q.pop();
			cout<<temp->data<<' ';
			
		}
	}

};

int main() {
	Btree t;
	t.root = t.newNode(1);
	t.root->left = t.newNode(2);
	t.root->right = t.newNode(3);
	t.root->left->left = t.newNode(4);
	t.root->left->right = t.newNode(5);
	t.root->right->left = t.newNode(6);
	t.root->right->right = t.newNode(7);
	cout<<t.height(t.root);
	cout<<endl;
	t.InorderTraversal(t.root);
	cout<<endl;
	return 0;
}