#include <iostream>
#include <queue>
#include <list>
#include <stack>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class Node{
public:
	int data;
	Node *left, *right;
	Node() : left(0), right(0) {}
	Node(int x) : left(0), right(0) {}
};

Node * newNode(int data) {
	Node * curr = new Node(data);
	return curr;
}

int largestBSTHelper(Node *node, int *min_ref, int *max_ref, int *max_size_ref, bool *is_bst_ref);

int largestBST(Node *node) {
	int min = INT_MIN;
	int max = INT_MAX;
	int max_size = 0;
	bool is_bst = 0;
	largestBSTHelper(node, &min, &max, &max_size, &is_bst);
	return max_size;
}

int largestBSTHelper(Node *node, int *min_ref, int *max_ref, int *max_size_ref, bool *is_bst_ref) {
	
	if (node == NULL) {
		is_bst_ref = 1;
		return 0;
	}

	int min = INT_MIN;
	bool left_flag = false;
	bool right_flag = false;
	int ls,rs;
	*max_ref = INT_MIN;
	ls = largestBSTHelper(node->left, min_ref, max_ref ,max_size_ref, is_bst_ref);
	if ( *is_bst_ref == 1 && node->data > *max_ref) {
		left_flag = true;
	}
	min = *min_ref;

}



int main() {

	return 0;
}