class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagramsResult;
        unordered_map<string, vector<string>> anagrams;
        unordered_map<string, vector<string>>::iterator it;
        for (int i = 0; i < strs.size(); i++) {
            string currentString = strs[i];
            std::sort(strs[i].begin(), strs[i].end());
            anagrams[strs[i]].push_back(currentString);
        }
        for (it = anagrams.begin(); it != anagrams.end(); it++) {
            anagramsResult.push_back(it->second);
        }
        return anagramsResult;
    }
};
