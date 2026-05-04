class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256, 0);
        for (int i = 0; i < t.size(); i++) {
            hash[t[i]]++;
        }
        
        int startIndex = -1;
        int l = 0, r = 0;
        int count = 0;
        int minLength = INT_MAX;
        while (r < s.size()) {
            char c = s[r];
            if (hash[c] > 0) {
                count++;
            }
            hash[c]--;
            while (count == t.size()) {
                if (r - l + 1 < minLength) {
                    minLength = r - l + 1;
                    startIndex = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    count--;        
                }
                l++;
            }
            r = r + 1;
        }
        return startIndex == -1 ? "" : s.substr(startIndex, minLength);
    }
};
