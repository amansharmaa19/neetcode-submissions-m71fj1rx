class PrefixTree {
    class Node {
        Node *nodes[26];
        bool isLast;
    public:
        Node() {
            for (int i = 0; i < 26; i++) {
                nodes[i] = nullptr;
            }
            isLast = false;
        }
        bool containsNode(char c) {
            if (nodes[c - 'a'] != nullptr) {
                return true;
            }
            return false;
        }
        void putNode(Node *node, char c) {
            nodes[c - 'a'] = node;
        }
        Node* nextNode(char c) {
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
        Node *start = root;
        for (int i = 0; i < word.size(); i++) {
            if (!start->containsNode(word[i])) {
                start->putNode(new Node(), word[i]);
            }
            start = start->nextNode(word[i]);
        }
        start->setLast();
    }
    
    bool search(string word) {
        Node *start = root;
        for (int i = 0; i < word.size(); i++) {
            if (!start->containsNode(word[i])) {
                return false;
            }
            start = start->nextNode(word[i]);
        }
        return start->getLast();
    }
    
    bool startsWith(string prefix) {
        Node *start = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!start->containsNode(prefix[i])) {
                return false;
            }
            start = start->nextNode(prefix[i]);
        }
        return true;
    }
};
