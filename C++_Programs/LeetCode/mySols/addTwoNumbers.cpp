/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 -> val == 0 && l1 -> next == NULL) return l2;
        if (l2 -> val == 0 && l2 -> next == NULL) return l1;
        int temp = l1 -> val + l2 -> val;
        int carry = 0;
        int add = 0;
        l1 = l1 -> next;
        l2 = l2 -> next;
        ListNode * newHead;
        ListNode * curr;
        if (temp/10==0) {
            add = temp;
            carry = 0;
            newHead = new ListNode(add);
            curr = newHead;
        }
        else {
            add = temp%10;
            temp /= 10;
            carry = temp;
            newHead = new ListNode(add);
            curr = newHead;
            if (!l1 && !l2) {
                curr -> next = new ListNode(carry);
                curr = curr -> next;
                return newHead;
            }
            carry = temp;
        }
        while (l1 && l2) {
            int temp = l1 -> val + l2 -> val + carry;
            carry = 0;
            if (temp/10==0) {
                add = temp;
                carry = 0;
                curr -> next = new ListNode(temp);
                curr = curr -> next;
            }
            else {
                add = temp%10;
                temp /= 10;
                carry = temp;
                curr -> next = new ListNode(add);
                curr = curr -> next;
                if (l1 -> next == NULL && l2 -> next == NULL) {
                    curr -> next = new ListNode(carry);
                    curr = curr -> next;
                }
            }
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while (l1) {
            int temp = l1 -> val + carry;
            carry = 0;
            if (temp >= 10) {
                carry = 1;
                add = temp % 10;
            }
            else {
                carry = 0;
                add = temp;
            }
            if (l1 -> next == NULL) {
                curr -> next = new ListNode(add);
                curr = curr -> next;
                if (carry==1) {
                    curr -> next = new ListNode(carry);
                    return newHead;
                }
                return newHead;
            }
            curr -> next = new ListNode(add);
            curr = curr -> next;
            l1 = l1 -> next;
        }
        while (l2) {
            int temp = l2 -> val + carry;
            carry = 0;
            if (temp >= 10) {
                carry = 1;
                add = temp % 10;
            }
            else {
                carry = 0;
                add = temp;
            }
            if (l2 -> next == NULL) {
                curr -> next = new ListNode(add);
                curr = curr -> next;
                if (carry==1) {
                    curr -> next = new ListNode(carry);
                    return newHead;
                }
                return newHead; 
            }
            curr -> next = new ListNode(add);
            curr = curr -> next;
            l2 = l2 -> next;
        }
        return newHead;
    }
};