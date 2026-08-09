class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) { 
            return "";
        }

        string firstString = strs[0];
        string prefix = "";
        int minLen = INT_MAX;
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (j < strs[i].size() && 
                j < firstString.size() &&
                firstString[j] == strs[i][j]) {
                j++;
            }
            minLen = min(minLen, j);
        }
        prefix = firstString.substr(0, minLen);
        if (prefix.empty()) {
            return "";
        }
        return prefix;
    }
};