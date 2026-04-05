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
    ListNode *reverse(ListNode *head) {
        ListNode *curr = head;
        ListNode *next = nullptr, *prev = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *firstHalf = head;
        ListNode *secondHalf = reverse(slow->next);
        slow->next = nullptr; // Break the list into halves

        ListNode *currNode = nullptr;
        if (!currNode) {
            currNode = firstHalf;
            firstHalf = firstHalf->next;
        }
        bool flag = true;
        while (firstHalf && secondHalf) {
            if (flag) {
                currNode->next = secondHalf;
                secondHalf = secondHalf->next;
                flag = false;
            } else {
                currNode->next = firstHalf;
                firstHalf = firstHalf->next;
                flag = true;
            }
            currNode = currNode->next;
        }
        if (firstHalf) {
            currNode->next = firstHalf;
        }
        if (secondHalf) {
            currNode->next = secondHalf;
        }
    }
};
