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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || head->next == NULL) return NULL;
        vector<ListNode *> ptrs;
        ListNode * current = head;
        do {
            ptrs.push_back(current);
            current = current->next;
        } while (current != NULL);
        if (n == 1) { // last element
            //free(ptrs[ptrs.size() - 1]);
            ptrs[ptrs.size() - 2]->next = NULL;
        } else if (n == ptrs.size()) { // first element
            head = head->next;
            //free(ptrs[0]);
        } else {
            ptrs[ptrs.size() - n - 1]->next = ptrs[ptrs.size() - n + 1];
            //free(ptrs[ptrs.size() - n]);
        }
        return head;
    }
};