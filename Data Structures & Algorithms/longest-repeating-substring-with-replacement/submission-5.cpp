class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0;
        int maxLength = 0, maxFrequency = 0;
        unordered_map<char, int> umap;
        while (r < s.length()) {
            char c = s[r];
            umap[c]++;
            maxFrequency = max(maxFrequency, umap[c]);
            if ((r - l + 1) - maxFrequency > k) {
                umap[s[l]]--;
                l++;
            }
            maxLength = max(maxLength, r - l + 1);
            r++;
        }
        return maxLength;
    }
};
