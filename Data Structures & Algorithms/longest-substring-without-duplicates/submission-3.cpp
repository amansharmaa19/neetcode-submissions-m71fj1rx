class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int left = 0;
        int right = 0;
        int hashTable[256];

        std::fill(std::begin(hashTable), std::end(hashTable), -1);
        while (right < s.length()) {
            if (hashTable[s[right]] != -1) {
                if (hashTable[s[right]] >= left)
                left = hashTable[s[right]] + 1;
            }
            hashTable[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
};
