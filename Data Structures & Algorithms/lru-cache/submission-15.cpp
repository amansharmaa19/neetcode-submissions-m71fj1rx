class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
    int cap;
    Node *head, *tail;
    unordered_map<int, Node*> cache;

    void insertAtHead(Node* node) {
        node->prev = head->next->prev;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.contains(key)) {
            return -1;
        }
        int result = cache[key]->val;
        Node *node = cache[key];
        cache.erase(key);
        deleteNode(node);
        insertAtHead(node);
        cache[key] = node;
        return result;
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) {
            Node *nodeToDelete = cache[key];
            cache.erase(key);
            deleteNode(nodeToDelete);
        }
        if (cache.size() == cap) {
            cache.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* newNode = new Node(key, value);
        insertAtHead(newNode);
        cache[key] = newNode;
    }
};
