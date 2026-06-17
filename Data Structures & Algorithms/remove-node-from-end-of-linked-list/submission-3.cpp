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
        if (!head) { // base case
            return head;
        }
        ListNode *curr = head;
        int totalCount = 0;
        while (curr) {
            curr = curr->next;
            totalCount++;
        }
        int targetNode = totalCount - n;
        if (targetNode == 0) {
            head = head->next;
            return head;
        }
        
        ListNode *prev = nullptr;
        int count = 0;
        curr = head;
        while (curr) {
            if (targetNode == count) {
                prev->next = curr->next;
                break;
            }
            prev = curr;
            curr = curr->next;
            count++;
        }
        return head;
    }
};
