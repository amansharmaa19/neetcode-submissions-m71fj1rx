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

        for (auto& [key, value] : anagramsMap) {
            result.push_back(value);
        }
        return result;
    }
};
