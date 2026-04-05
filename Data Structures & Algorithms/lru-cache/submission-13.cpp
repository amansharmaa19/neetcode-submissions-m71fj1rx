struct ListNode {
    int key;
    int val;
    ListNode *prev;
    ListNode *next;
    ListNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
    ListNode(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int size;
    ListNode *head;
    ListNode *tail;
    unordered_map<int, ListNode*> map;

    void deleteNode(ListNode *node) {
    //    ListNode *delNext = node->next;
    //    ListNode *delPrev = node->prev;
       
       node->prev->next = node->next;
       node->next->prev = node->prev;

    //    delNext->prev = delPrev;
    //    delPrev->next = delNext;
    }

    void insertAtHead(ListNode *newNode) {
        ListNode *oldNode = head->next;
        head->next = newNode;
        oldNode->prev = newNode;
        newNode->next = oldNode;
        newNode->prev = head;
    }

public:
    LRUCache(int capacity) {
        size = capacity;
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!map.contains(key)) {
            return -1;
        }
        int result = map[key]->val;
        ListNode *node = map[key];
        map.erase(key);
        deleteNode(node);
        insertAtHead(node);
        map[key] = node;
        return result;
    }
    
    void put(int key, int value) {
        if (map.contains(key)) {
            ListNode *nodeToRemove = map[key];
            deleteNode(nodeToRemove);
            map.erase(key);
        }
        if (map.size() == size) {
            map.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        ListNode *newNode = new ListNode(key, value);
        insertAtHead(newNode);
        map[key] = newNode;
    }
};
