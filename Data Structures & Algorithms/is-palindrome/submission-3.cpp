class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for (const auto& val : s) {
            if (val >= 'a' && val <= 'z' || val >= 'A' && val <= 'Z' || val >= '0' && val <= '9') {
                temp += tolower(val);
            }
        }
        for (int i = 0, j = temp.length() - 1; i <= j; i++, j--) {
            if (temp[i] != temp[j]) {
                return false;
            }
        }
        return true;
    }
};
