class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;

        // insert words in set for easy access.
        for (int i = 0; i < wordList.size(); i++) {
            s.insert(wordList[i]);
        }
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            string word = q.front().first;
            int len = q.front().second;
            q.pop();
            for (int i = 0; i < word.length(); i++) {
                string temp = word;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;
                    if (s.contains(temp)) {
                        if (temp == endWord) {
                            return len + 1;
                        }
                        q.push({temp, len + 1});
                        s.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};
