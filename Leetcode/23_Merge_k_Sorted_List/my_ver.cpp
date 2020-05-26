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
class MyCompare {
public:
    int operator() (const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.first > p2.first;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare> queue;
        vector<ListNode *> curs = lists;
        ListNode head;
        ListNode * rcur = &head;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) queue.push(make_pair(lists[i]->val, i));
        }
        while(queue.size()) {
            pair<int, int> top = queue.top();
            rcur->next = new ListNode(top.first);
            rcur = rcur->next;
            queue.pop();
            curs[top.second] = curs[top.second]->next;
            if (curs[top.second]) {
                queue.push(make_pair(curs[top.second]->val, top.second));
            }
        }
        return head.next;
    }
};

