/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> clone;
        Node *curr = head;
        while (curr) {
            clone[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr) {
            clone[curr]->next = clone[curr->next];
            clone[curr]->random = clone[curr->random];
            curr = curr->next;
        }
        return clone[head];
    }
};
