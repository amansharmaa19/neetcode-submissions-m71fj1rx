class Solution {
public:
    bool isPalindrome(string s) {
        string palindromicString = "";
        for (int i = 0; i < s.length(); i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= '0' && s[i] <= '9')
            ) {
                palindromicString += std::tolower(s[i]);
            }   
        }
        int i = 0;
        int j = palindromicString.length() - 1;
        while (i <= j) {
            if (palindromicString[i] != palindromicString[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
