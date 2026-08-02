class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for (const string& it : strs) {
            str.append(to_string(it.length()));
            str.append("#");
            str.append(it);
        }
        return str;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string temp = "";
        int i = 0;
        while (i < s.length()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            j++;
            result.push_back(s.substr(j, len));
            i = j + len;
        }
        return result;
    }
};
