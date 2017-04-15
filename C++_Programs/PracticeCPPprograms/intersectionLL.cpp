#include <iostream>
using namespace std;

class Node {
	int data;
	Node * next;
public:
	Node(int d) : data(d), next(nullptr) {}
	friend class LinkedList;
};

class LinkedList {
	Node *head;
public:
	void printList(Node * curr) {
		while(curr!=NULL) {
			cout<<curr->data<<"-->";
			curr = curr->next;
		}
	}
	int listLen(Node * curr) {
		int count=0;
		while(curr!=NULL) {
			curr += 1;
		}
		return curr;
	}
	Node * intersectionOfLists(Node * h1, Node * h2) {
		int l1 = listLen(h1);
		int l2 = listLen(h2);
		Node * ptr1,ptr2;
		if(l1>=l2) {
			ptr1 = h1;
			ptr2 = h2;
		}
		else() {
			ptr1 = h2;
			ptr2 = h1;
		}
		
	}
};

int main() {

	return 0;
}