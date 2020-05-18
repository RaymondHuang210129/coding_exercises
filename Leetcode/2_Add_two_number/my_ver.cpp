/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = NULL;
        ListNode* p3 = NULL;
        ListNode* p1,* p2;
        int carry = 0;
        while(true) {
            if (!l3) {
                l3 = new ListNode();
                p3 = l3;
                p1 = l1;
                p2 = l2;
            } else {
                p3->next = new ListNode();
                p3 = p3->next;
                p1 = p1->next;
                p2 = p2->next;
            }
            int sum = p1->val + p2->val + carry;
            carry = 0;
            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            }
            p3->val = sum;
            if (p1->next == NULL && p2->next == NULL) {
                if (carry) {
                    p3->next = new ListNode(1);
                }
                return l3;
            }
            if (p1->next == NULL) {
                while (p2->next != NULL) {
                    p2 = p2->next;
                    if (p2->val + carry >= 10) {
                        p3->next = new ListNode(p2->val + carry - 10);
                    } else {
                        p3->next = new ListNode(p2->val + carry);
                        carry = 0;
                    }
                    p3 = p3->next;
                }
                if (carry) {
                    p3->next = new ListNode(1);
                }
                return l3;
            }
            if (p2->next == NULL) {
                while (p1->next != NULL) {
                    p1 = p1->next;
                    if (p1->val + carry >= 10) {
                        p3->next = new ListNode(p1->val + carry - 10);
                    } else {
                        p3->next = new ListNode(p1->val + carry);
                        carry = 0;
                    }
                    p3 = p3->next;
                }
                if (carry) {
                    p3->next = new ListNode(1);
                }
                return l3;
            }
        }
    }
};