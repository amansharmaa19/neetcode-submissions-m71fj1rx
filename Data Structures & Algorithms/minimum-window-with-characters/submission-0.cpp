class Solution {
public:
    string minWindow(string s, string t) {
        // Update all the k elements in the hashTable.
        int hash[256] = {0};
        for (int i = 0; i < t.size(); i++) {
            hash[t[i]]++;
        }

        int left = 0;
        int right = 0;
        int minLength = INT_MAX;
        int startIndex = -1;
        int count = 0;

        while (right < s.size()) {
            if (hash[s[right]] > 0) {
                count++;
            }
            hash[s[right]]--;
            
            while (count == t.size()) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    startIndex = left;
                }
                    
                hash[s[left]]++;
                if (hash[s[left]] > 0) {
                    count--;
                }
                left++;
            }
            right++;
        }
        return startIndex == -1 ? "" : s.substr(startIndex, minLength);
    }
};
