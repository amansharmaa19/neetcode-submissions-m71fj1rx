class WordDictionary {
    class Node {
        Node* nodes[26];
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
        Node* getNode(char c) {
            return nodes[c - 'a'];
        }
        void setLast() {
            isLast = true;
        }
        bool isLastSet() {
            return isLast;
        }
    };
    
    bool dfs(string& word, int index, Node *node) {
        if (index == word.size()) {
            return node->isLastSet();
        }

        char c = word[index];

        // If char already exists
        if (c != '.') {
            if (!node->containsNode(c)) {
                return false;
            }
            return dfs(word, index + 1, node->getNode(c));
        }

        // wildcard
        for (int i = 0; i < 26; i++) {
            if (node->containsNode('a' + i)) {
                if (dfs(word, index + 1, node->getNode('a' + i))) {
                    return true;
                }
            }
        }

        return false;
    }

    Node *root;

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* start = root;
        for (int i = 0; i < word.size(); i++) {
            if (!start->containsNode(word[i])) {
                start->putNode(new Node(), word[i]);
            }
            start = start->getNode(word[i]);
        }
        start->setLast();
    }
    
    bool search(string word) {
       return dfs(word, 0, root);
    }
};
