class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hashTable;
        for (int i = 0; i < s.size(); i++) {
            hashTable[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++) {
            hashTable[t[i]]--;
        }
        unordered_map<char, int>::iterator it;
        for (it = hashTable.begin(); it != hashTable.end(); it++) {
            if (it->second != 0) {
                return false;
            }
        }
        return true;
    }
};
