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
    ListNode* mergeList(ListNode *l1, ListNode *l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        ListNode *newHead = nullptr;
        ListNode *curr = nullptr;
        if (l1->val < l2->val) {
            newHead = curr = l1;
            l1 = l1->next;
        } else {
            newHead = curr = l2;
            l2 = l2->next;
        }
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if (l1 && !l2) {
            curr->next = l1;
        }
        if(!l1 && l2) {
            curr->next = l2;
        }
        return newHead;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr;
        if (lists.size() == 0) {
            return head;
        } else if (lists.size() == 1) {
            return lists[0];
        }
        // ListNode *newHead = mergeList(lists[0], lists[1]);
        ListNode *newHead = nullptr;
        for (int i = 0; i < lists.size(); i++) {
            newHead = mergeList(newHead, lists[i]);
        }
        return newHead;
    }
};
