class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(nums.size() + 1);
        unordered_map<int, int> unorderedMap;
        unordered_map<int, int>::iterator it;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            unorderedMap[nums[i]]++;
        }
        for (it = unorderedMap.begin(); it != unorderedMap.end(); it++) {
            buckets[it->second].push_back(it->first);
        }
        int count = 0;
        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int j = 0; j < buckets[i].size(); j++) {
                result.push_back(buckets[i][j]);
                count++;
                if (count == k) {
                    return result;
                }
            }
        }
        return result;
    }
};
