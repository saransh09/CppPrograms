#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* A, int B) {
    ListNode *h, *l, *temp;
    h = A;
    l = A;
    int length;
    temp = A;
    while(temp!=NULL) {
        temp = temp->next;
    }
    int x;
    x = B%length;
    if (x==0) {
        return A;
    }
    int y = length - x;
    temp = A;
    while(y>1) {
        temp = temp->next;
    }
    l = temp;
    h = temp->next;
    temp = h;
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = A;
    l->next = NULL;
    return h;
}

struct List {
public:
	ListNode *head;
	List(): head(0) {}
	ListNode * newNode(int x) {
		ListNode * temp = new ListNode(x);
		return temp;
	}
};

int main() {
	List L1;
	L1->next = newNode(1);
}