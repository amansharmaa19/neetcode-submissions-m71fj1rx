class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        for (int i = 0; i < s.length(); i++) {
            int hashTable[256] = {0};
            int length = 0;
            for (int j = i; j < s.length(); j++) {
                if (hashTable[s[j]] > 0) {
                    break;
                }
                hashTable[s[j]] = 1;
                length++;
            }
            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
};
