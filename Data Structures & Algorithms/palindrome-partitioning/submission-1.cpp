class Solution {
    bool isPalindrome(string& s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void solvePartition(
        int index,
        string &s,
        vector<vector<string>>& result,
        vector<string>& path
    ) {
        if (index == s.length()) {
            result.push_back(path);
            return;
        }
        for (int i = index; i < s.length(); i++) {
            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                solvePartition(i + 1, s, result, path);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        solvePartition(0, s, result, path);
        return result;
    }
};
