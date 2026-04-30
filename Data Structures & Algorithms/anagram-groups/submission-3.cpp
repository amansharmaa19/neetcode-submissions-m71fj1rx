class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> anagramsMap;
        for (auto& val : strs) {
            string temp = val;
            sort(val.begin(), val.end());
            anagramsMap[val].push_back(temp);
        }

        for (auto& it: anagramsMap) {
            result.push_back(it.second);
        }
        return result;
    }
};
