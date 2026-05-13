class PrefixTree {
    class Node {
        vector<Node*> nodes;
        bool isLast;
    public:
        Node() {
            nodes = vector<Node*>(26, nullptr);
            isLast = false;
        }
        bool containsKey(char c) {
            if (nodes[c - 'a'] != nullptr) {
                return true;
            }
            return false;
        }
        void putNode(char c, Node* node) {
            nodes[c - 'a'] = node;
        }
        Node* getNext(char c) {
            return nodes[c - 'a'];
        }
        void setLast() {
            isLast = true;
        }
        bool getLast() {
            return isLast;
        }
    };
    Node *root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->containsKey(word[i])) {
                curr->putNode(word[i], new Node());
            }
            curr = curr->getNext(word[i]);
        }
        curr->setLast();
    }
    
    bool search(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->containsKey(word[i])) {
                return false;
            }
            curr = curr->getNext(word[i]);
        }
        return curr->getLast();
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!curr->containsKey(prefix[i])) {
                return false;
            }
            curr = curr->getNext(prefix[i]);
        }
        return true;
    }
};
