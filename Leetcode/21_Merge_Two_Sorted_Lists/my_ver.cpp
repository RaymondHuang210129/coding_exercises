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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * cur1 = l1, * cur2 = l2;
        ListNode head(0);
        ListNode * cur3 = &head;
        while(cur1 || cur2) {
            if (cur1 && (!cur2 || (cur2 && cur1->val < cur2->val))) {
                cur3->next = cur1;
                cur1 = cur1->next;
                cur3 = cur3->next;
            } else {
                cur3->next = cur2;
                cur2 = cur2->next;
                cur3 = cur3->next;
            }
        }
        return head.next;
    }
};