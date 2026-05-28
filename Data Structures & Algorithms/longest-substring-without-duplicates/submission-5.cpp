class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int maxLength = 0;
        unordered_map<char, int> charToIndex;
        while(r < s.length()) {
            char c = s[r];
            if (charToIndex.find(c) != charToIndex.end()) {
                if (charToIndex[c] >= l) {
                    l = charToIndex[c] + 1;
                }
            }
            charToIndex[c] = r;
            maxLength = max(maxLength, r - l + 1);
            r++;
        }
        return maxLength;
    }
};
