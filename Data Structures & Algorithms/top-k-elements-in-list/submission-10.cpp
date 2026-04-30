class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(nums.size() + 1);
        unordered_map<int, int> valueToCount;
        vector<int> result;
        for (const auto& val : nums) {
            valueToCount[val]++;
        }
        for (const auto& it : valueToCount) {
            buckets[it.second].push_back(it.first);
        }

        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int j = 0; j < buckets[i].size(); j++) {
                result.push_back(buckets[i][j]);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        return result;
    }
};
