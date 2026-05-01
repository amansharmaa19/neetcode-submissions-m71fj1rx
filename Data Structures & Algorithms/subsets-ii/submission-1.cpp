class Solution {
    void subsetsUtil(
        int index,
        vector<int>& nums,
        vector<int>& eachSubset,
        vector<vector<int>>& result
    ) {
        result.push_back(eachSubset);
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }
            eachSubset.push_back(nums[i]);
            subsetsUtil(i + 1, nums, eachSubset, result);
            eachSubset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> eachSubset;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        subsetsUtil(0, nums, eachSubset, result);
        return result;
    }
};
