#include <iostream>
#include <stack>
#include <list>
using namespace std;

class Node {
public:
	int val;
	Node *next;
	Node() : next(0) {}
	Node(int x) : val(x), next(0) {}
};


int isPalindrome(Node *A){
	stack<int> S1;
	Node *curr = A;
	while(curr!=NULL) {
		S1.push(curr->val);
		curr = curr->next;
	}
	while(!S1.empty()) {
		if (S1.top()==A->val) {
			S1.pop();
			A = A->next;
		}
		else if (S1.top()!=A->val) {
			return 0;
		}
	}
	return 1;
}

Node* deleteDuplicate(Node *A){
	Node *ptr1 = A;
	Node *ptr2 = A;
	ptr1 = ptr1->next;
	while(ptr1!=NULL){
		if(ptr1->val!=ptr2->val) {
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		else if(ptr1->val==ptr2->val){
			Node *temp = ptr1;
			ptr1 = ptr1->next;
			ptr2->next = ptr1;
		}
	}
	return A;
}

Node * deleteDuplicateDistinct(Node *A) {
	Node *ptr1=A,*ptr2=A,*ptr3=A;
	ptr1 = A->next;
	while(ptr1!=NULL){
		if(ptr1->val!=ptr2->val){

		}
	}
}

void printList(Node *A){
	while(A){
		cout<<A->val<<' ';
		A = A->next;
	}
}

Node *removeNthFromLast(Node *A,int B){
	int length = 0;
	Node *curr = A;
	while(curr){
		length++;
		curr = curr->next;
	}
	if(length==1){
		return NULL;
	}
	int s = length-B;
	s--;
	if(s==-1){
		return A->next;
	}
	curr = A;
	while(s>0){
		curr = curr->next;
		s--;
	}
	if(curr->next==NULL){
		return A;
	}
	curr->next = curr->next->next;
	return A;
}

Node * rotateList(Node *A, int B){
	Node *curr = A;
	while(B>0){
		curr = curr->next;
	}
	Node *newNode;
	Node *temp = curr->next;
	newNode = new Node(temp->val);
	temp = temp->next;
	Node *currnewNode=newNode->next;
	while(temp){
		currnewNode->next = new Node(temp->val);
		temp = temp->next;
		currnewNode = currnewNode->next;
	}
	while(A!=curr->next){
		currnewNode->next = new Node(A->val);
		A = A->next;
		currnewNode = currnewNode->next;
	}
	return newNode;
}

int main() {
	Node *head;
	head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	// deleteDuplicate(head);
	printList(head);
	cout<<endl;
	// cout<<isPalindrome(head);
	printList(rotateList(head,2));

	return 0;
}