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
    ListNode *reverse(ListNode *head, int k, ListNode *&nextStart) {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        while (curr && k--) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        nextStart = next;
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) {
            return head;
        }

        // Compute the total size of LL to reverse
        ListNode *curr = head;
        int totalNodes = 0;
        while (curr) {
            curr = curr->next;
            totalNodes++;
        }

        // Find total groups possible
        int totalGroups = totalNodes / k;
        if (totalGroups < 1) {
            return head;
        }
        
        ListNode *prevStart = head;
        ListNode *newHead = nullptr;
        ListNode *nextStart = nullptr;
        while (totalGroups--) {
            ListNode *temp = reverse(head, k, nextStart);
            if (!newHead) {
                newHead = temp;
            } else {
                prevStart->next = temp;
            }
            prevStart = head;
            head = nextStart;
        }
        if (nextStart) {
            prevStart->next = nextStart;
        }
        return newHead;
    }
};
