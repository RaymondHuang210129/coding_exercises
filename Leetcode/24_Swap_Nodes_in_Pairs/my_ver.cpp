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
    ListNode* swapPairs(ListNode* head) {
        ListNode myHead(0, head);
        ListNode * cur1 = &myHead;
        ListNode * cur2, * cur3;
        while (cur1->next != NULL && cur1->next->next != NULL) {
            cur2 = cur1->next;
            cur3 = cur2->next;
            cur2->next = cur3->next;
            cur3->next = cur2;
            cur1->next = cur3;
            cur1 = cur2;
        }
        return myHead.next;
    }
};