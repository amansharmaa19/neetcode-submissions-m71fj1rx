class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLength = 0;
        int maxFrequency = 0;
        int hash[26] = {0};
        int left = 0, right = 0;
        while (right < s.size()) {
            hash[s[right] - 'A']++;
            maxFrequency = max(maxFrequency, hash[s[right] - 'A']);
            if (((right - left + 1) - maxFrequency) > k) {
                hash[s[left] - 'A']--;
                left++;
            }
            if ((right - left + 1) - maxFrequency <= k) {
                maxLength = right - left + 1;
            }
            right++;
        }
        return maxLength;
    }
};
