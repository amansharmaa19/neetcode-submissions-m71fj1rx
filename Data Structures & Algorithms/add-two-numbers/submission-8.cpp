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

    int calculateLength(ListNode *head) {
        int count = 0;
        while (head) {
            head = head->next;
            count++;
        }
        return count;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        }

        int l1Length = calculateLength(l1);
        int l2Length = calculateLength(l2);
        
        ListNode *curr = nullptr;
        ListNode *prev = nullptr;
        ListNode *head = nullptr;
        if (l1Length >= l2Length) {
            curr = head = l1;
        } else {
            curr = head = l2;
        }

        int quotient = 0;
        while (l1 || l2) {
            int sum  = 0;
            if (l1) {
                sum = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += quotient;  
            int rem = sum % 10;
            quotient = sum / 10;

            curr->val = rem;
            prev = curr;
            curr = curr->next;
        }
        if (quotient) {
            prev->next = new ListNode(1);
        }
        return head;
    }
};
