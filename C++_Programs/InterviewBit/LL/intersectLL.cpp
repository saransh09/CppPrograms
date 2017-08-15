#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) : val(x) {}
};

int findLength(ListNode * A) {
    ListNode *curr = A;
    int length = 0;
    while(curr) {
        length++;
        curr = curr -> next;
    }
    return length;
} 
 
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if(!headA || !headB)
        return NULL;
    int lenA = findLength(headA), lenB = findLength(headB);
    int lenDiff = lenA - lenB;
    ListNode *pa = headA;
    ListNode *pb = headB;
    if(lenDiff > 0) {
        while(lenDiff != 0) {
            pa = pa->next;
            lenDiff--;
        }
    }
    else if(lenDiff < 0) {
        while(lenDiff != 0) {
            pb = pb->next;
            lenDiff++;
        }
    }
    while(pa && pb) {
        if(pa == pb)
            return pa;
        pa = pa->next;
        pb = pb->next;
    }
    return NULL;
}

int main() {


	return 0;
}