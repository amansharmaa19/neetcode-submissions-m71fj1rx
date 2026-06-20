class Solution {
    void subsetsUtil(
        int index,
        vector<int>& nums,
        vector<int>& eachSubset,
        vector<vector<int>>& result
    ) {
        result.push_back(eachSubset);
        for (int i = index; i < nums.size(); i++) {
            eachSubset.push_back(nums[i]);
            subsetsUtil(i + 1, nums, eachSubset, result);
            eachSubset.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> eachSubset;
        subsetsUtil(0, nums, eachSubset, result);
        return result;
    }
};
