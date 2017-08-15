#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list. */
 struct ListNode {
 int val;
 ListNode *next;
 // ListNode() : next(NULL) {}
 ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    int findMin(vector<ListNode*> & lists, vector<bool> isValid) {
        int smallest = INT_MAX;
        int smallestIndex = -1;
        for (int i = 0 ; i < lists.size() ; i++) {
            if (isValid[i]==false) continue;
            if (lists[i]->val < smallest) {
                smallest = lists[i]->val;
                smallestIndex = i; 
            }
        }
        return smallestIndex;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        int boolSum = n;
        ListNode *head;
        ListNode *mainCurrent;
        vector<bool> isValid(n,true);
        for (int i = 0 ; i < n ; i++) {
            if (lists[i]==NULL) {isValid[i]=false; boolSum--;} 
        }
        int index = findMin(lists,isValid);
        head = lists[index];
        lists[index] = lists[index]->next;
        mainCurrent = head;
        mainCurrent -> next = NULL;        
        if (lists[index]==NULL) {isValid[index] = false; boolSum--;}; 
        while (boolSum!=0) {
            index = findMin(lists,isValid);
            mainCurrent -> next = lists[index];
            mainCurrent = mainCurrent -> next;
            lists[index] = lists[index]->next;
            if (lists[index]==NULL) {isValid[index] = false; boolSum--;};
        }
        return head;
    }
};

int main() {
    ListNode * l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(7);
    ListNode * l2 = new ListNode(0);
    l2 -> next = new ListNode(3);
    l2 -> next -> next = new ListNode(9);
    ListNode * l3 = new ListNode(-5);
    l3 -> next = new ListNode(2);
    vector<ListNode*> l;
    l.push_back(l1);
    l.push_back(l2);
    l.push_back(l3);
    Solution s;
    ListNode * t = s.mergeKLists(l);
    while(t!=NULL) {
        cout<< t->val<<' ';
        t = t -> next;
    }
    return 0;
}