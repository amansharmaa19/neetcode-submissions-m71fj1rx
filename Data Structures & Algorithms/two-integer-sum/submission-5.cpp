class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> twoSumResult;
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            int key = target - nums[i];
            if (umap.contains(key)) {
                twoSumResult.push_back(umap[key]);
                twoSumResult.push_back(i);
            } else {
                umap[nums[i]] = i;
            }
        }
        return twoSumResult;
    }
};
