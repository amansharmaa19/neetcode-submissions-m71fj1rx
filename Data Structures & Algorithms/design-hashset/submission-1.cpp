class MyHashSet {
    vector<bool> hashTable;
public:
    MyHashSet() {
        hashTable.resize(1000001, false);
    }
    
    void add(int key) {
        hashTable[key] = true;
    }
    
    void remove(int key) {
        hashTable[key] = false;
    }
    
    bool contains(int key) {
        if (hashTable[key]) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */