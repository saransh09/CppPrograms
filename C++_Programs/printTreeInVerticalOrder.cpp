#include <bits/stdc++.h>
using namespace std;

class Node {
	int key;
	Node *left;
	Node *right;
public:
	Node() : left(0) , right(0) {}
	Node(int key) : key(key), left(0), right(0) {}
	Node * newNode(int key) {
		Node *newNode = new Node(key);
	}
	void getVerticalOrder(Node *root, int hd, map<int, vector<int> > & m) {
		
	}
};

int main() {

	return 0;
}