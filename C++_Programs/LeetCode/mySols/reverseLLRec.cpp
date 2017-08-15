#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    
    void reverseList(ListNode * head, ListNode * prev) {
        if (head == NULL) return;
        prev = head;
        head = head -> next;
        head -> next = prev;
        reverseList(head->next,prev);
        return;
    }
    
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        if (!head -> next) return head;
        ListNode *temp = head;
        while (temp->next) temp = temp -> next;
        ListNode *prev = NULL;
        reverseList(head,prev);
        return temp;
    }
};

int main() {
	ListNode * head = new ListNode(1);
	head -> next = new ListNode(2);
	head -> next = new ListNode(3);
	head -> next = new ListNode(4);
	Solution s;
	ListNode *temp =s.reverseList(head);
	while(!temp) {
		cout<<temp -> val<<' ';
	}
	cout<<endl;
	return 0;
} 