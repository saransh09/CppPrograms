#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
	Node() : left(0), right(0) {}
	Node(int x) : data(x), left(0), right(0) {}
};

Node * newNode(int x) {
	Node * temp = new Node(x);
	return temp;
}

void inorderPrint(Node * root){
	if(!root) return;
	inorderPrint(root->left);
	cout<<root->data<<' ';
	inorderPrint(root->right);
}

Node * minValueNode(Node * root){
	Node * curr = root;
	while(curr -> left) curr = curr -> left;
	return curr;
}

Node * insert(Node * node, int x) {
	if(!node) return newNode(x);
	else if(x < node -> data) node -> left = insert(node -> left, x);
	else if(x > node -> data) node -> right = insert(node -> right,x);
	return node;
}

Node * deleteNode(Node *root, int x) {
	if(!root) return root;
	else if(x < root -> data) root -> left =  deleteNode(root->left,x);
	else if(x > root -> data) root -> right =  deleteNode(root->right,x);
	else{
		if(!(root->left)) {
			Node * temp = root -> right;
			free(root);
			return temp;
		}
		else if(!(root->right)) {
			Node * temp = root -> left;
			free(root);
			return temp;
		}
		Node * temp = minValueNode(root -> right);
		root -> data = temp -> data;
		root -> right = deleteNode(root -> right, temp -> data);
	}
	return root;
}

void findPreSuc(Node * root, Node * & pre, Node * & suc, int x){
	if(!root) return;
	if(root -> data == x){
		if(root -> left){
			Node * temp = root -> left;
			while(temp -> right) temp = temp -> right;
			pre = temp;
		}
		else if(root -> right){
			Node * temp = root -> right;
			while(temp->left) temp = temp -> left;
			suc = temp; 
		}
	}
	if(root -> data > x){
		suc = root;
		findPreSuc(root->left, pre,suc,x);
	}
	else if(root -> data < x){
		pre = root;
		findPreSuc(root->right,pre,suc,x);
	}
}



int main() {
	// Node * root = NULL;
	// root = insert(root, 50);
 //    insert(root, 30);
 //    insert(root, 20);
 //    insert(root, 40);
 //    insert(root, 70);
 //    insert(root, 60);
 //    insert(root, 80);
 //    inorderPrint(root);
 //    printf("Inorder traversal of the given tree \n");
 //    inorderPrint(root);
 
 //    printf("\nDelete 20\n");
 //    root = deleteNode(root, 20);
 //    printf("Inorder traversal of the modified tree \n");
 //    inorderPrint(root);
 
 //    printf("\nDelete 30\n");
 //    root = deleteNode(root, 30);
 //    printf("Inorder traversal of the modified tree \n");
 //    inorderPrint(root);
 
 //    printf("\nDelete 50\n");
 //    root = deleteNode(root, 50);
 //    printf("Inorder traversal of the modified tree \n");
 //    inorderPrint(root);
 
 //    return 0;

	Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
 
    Node* pre = NULL, *suc = NULL;
 
    findPreSuc(root, pre, suc, 65);
    if (pre != NULL)
      cout << "Predecessor is " << pre->data << endl;
    else
      cout << "No Predecessor";
 
    if (suc != NULL)
      cout << "Successor is " << suc->data << endl;
    else
      cout << "No Successor";

	return 0;
}