#include <iostream>
#include <queue>
#include <stack>
#include <limits.h>
#include <list>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;
	Node() : left(0), right(0) {}
	Node(int x) : data(x), left(0), right(0) {}
};

Node * newNode(int item) {
	Node *temp = new Node(item);
	return temp;
}

void printInOrder(Node *curr) {
	if (curr == NULL) {
		return;
	}
	printInOrder(curr->left);
	cout<<curr->data<<' ';
	printInOrder(curr->right);
}

Node * search(Node *curr, int data) {
	if (curr==NULL || curr->data == data ) {
		return curr;
	}


	if (curr->data < data) {
		return search(curr->right,data);
	}
	else{
		return search(curr->left,data);
	}
}

Node * insert(Node * curr, int data) {
	if (curr == NULL) {
		return newNode(data);
	}
	if (data < curr->data) {
		curr->left = insert(curr->left,data);
	}
	else if(data > curr->data) {
		curr -> right = insert(curr->right,data);
	}
}

void findPreSuc(Node *root, Node * & pre, Node * & suc, int data) {
	if (root == NULL) {
		return;
	}
	if ( root -> data == data) {
		if ( root -> left != NULL) {
			Node * temp = root ->left;
			while(temp->right) {
				temp = temp ->right;
			}
			pre = temp;
		}
		if ( root -> right != NULL) {
			Node * temp = root -> right;
			while(temp -> left) {
				temp = temp -> left;
			}
			suc = temp;
		}
	}
	if (data < root->data) {
		suc = root;
		findPreSuc(root->left,pre,suc,data);
	}
	else {
		pre = root;
		findPreSuc(root->right,pre,suc,data);
	}
}

int isBSTHelper(Node *curr, int min, int max);

int isBST(Node *node) {
	return (isBSTHelper(node, INT_MIN,INT_MAX));
}

int isBSTHelper(Node *curr, int min, int max) {
	
	if (curr == NULL) {
		return 1;
	}

	if (curr -> data < min || curr -> data > max) {
		return 0;
	}

	return isBSTHelper(curr -> left, min, curr->data-1) && isBSTHelper(curr -> right, curr->data+1, max);
}

bool isbst(Node *root) {
	static Node *prev = NULL;
	if (root) {
		if(!isbst(root->left)) {
			return false;
		}
		if(prev!=NULL && root->data <= prev->data) {
			return false;
		}
		prev = root;
		return isbst(root->right);
	}
	return true;
}

Node * lca(Node * root, int n1, int n2) {
	if (root == NULL) {
		return NULL;
	}
	if (root -> data > n1 && root -> data > n2) {
		return lca(root->left, n1, n2);
	}
	if (root -> data < n1 && root -> data < n2) {
		return lca(root->right, n1,n2);
	}
	return root;
}

Node *minValue(Node * curr) {
	Node * temp = curr;
	while(temp->left != NULL) {
		temp = temp -> left;
	}
	return temp;
}

Node * inOrderSuccessor(Node * root, Node *n) {
	if (n -> right != NULL) {
		return minValue(n -> right);
	}

	Node * succ = NULL;

	while (root != NULL) {
		if ( n -> data < root -> data) {
			succ = root;
			root = root -> left;
		}
		else if ( n->data > root -> data) {
			root = root -> right;
		}
		else {
			break;
		}
	}
	return succ;
}

Node * sortedArraytoBST(int *arr, int start, int end) {
	if ( start > end ) {
		return NULL;
	}

	int mid = (start + end) / 2;
	Node *root = newNode(arr[mid]);
	root -> left = sortedArraytoBST(arr, start, mid-1);
	root -> right = sortedArraytoBST(arr, mid+1,end);
	return root;
}





int main() {
	Node * root;
	root = insert(root,50);
	// insert(root,20);
	insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printInOrder(root);
	// Node* pre = NULL, *suc = NULL;
 // 	int data = 65;
 //    findPreSuc(root, pre, suc, data);	
 //    if (pre != NULL)
 //      cout << "Predecessor is " << pre->data << endl;
 //    else
 //      cout << "No Predecessor";
 
 //    if (suc != NULL)
 //      cout << "Successor is " << suc->data;
 //    else
 //      cout << "No Successor";
 //    return 0;


	return 0;
}