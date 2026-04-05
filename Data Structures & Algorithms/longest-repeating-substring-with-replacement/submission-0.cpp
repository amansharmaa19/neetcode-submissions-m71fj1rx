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
            int length = right - left + 1;
            if ((length - maxFrequency) > k) {
                hash[s[left] - 'A']--;
                left++;
            }
            if (length - maxFrequency <= k) {
                maxLength = length;
            }
            right++;
        }
        return maxLength;
    }
};
