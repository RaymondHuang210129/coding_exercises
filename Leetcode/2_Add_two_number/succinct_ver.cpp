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
        ListNode* l3 = NULL, * p3 = NULL;
        ListNode* p1 = l1, * p2 = l2;
        int cur_sum = 0;
        while (p1 != NULL || p2 != NULL) {
            if (p1 != NULL) {
                cur_sum += p1->val;
                p1 = p1->next;
            } else if (!cur_sum) {
                p3->next = p2;
            }
            if (p2 != NULL) {
                cur_sum += p2->val;
                p2 = p2->next;
            } else if (!cur_sum) {
                p3->next = p1;
            }
            if (l3 == NULL) {
                p3 = l3 = new ListNode(cur_sum % 10);
            } else {
                p3->next = new ListNode(cur_sum % 10);
                p3 = p3->next;
            }
            cur_sum /= 10;
        }
        if (cur_sum) {
            p3->next = new ListNode(1);
        }
        return l3;
    }
};