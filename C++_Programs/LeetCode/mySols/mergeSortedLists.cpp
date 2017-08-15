#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return NULL;
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *prev, *head, *curr1, *curr2;
        head = NULL;
        prev = NULL;
        curr1 = l1;
        curr2 = l2;
        if (curr1->val < curr2->val) {
            head = curr1;
            prev = curr1;
            curr1 = curr1 -> next;
        }
        else {
            head = curr2;
            prev = curr2;
            curr2 = curr2->next;
        }
        while(curr1 && curr2) {
            if (curr1 -> val < curr2 -> val) {
                prev -> next = curr1;
                prev = curr1;
                curr1 = curr1 -> next;
            }
            else {
                prev -> next = curr2;
                prev = curr2;
                curr2 = curr2 -> next;
            }
        }
        while(curr1) {
            prev -> next = curr1;
            curr1 = curr1 -> next;
        }
        while(curr2) {
            prev -> next = curr2;
            curr2 = curr2 -> next;
        }
        return head;
    }
};

int main() {
	ListNode L1(1);
	ListNode L2(0);
	L1 -> next = new ListNode(3);
	L1 -> next = new ListNode(4);
	return 0;
}