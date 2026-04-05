class Solution {
public:

    void subsetUtil(
        vector<int> &nums,
        vector<int> &res,
        vector<vector<int>> &totalSubsets,
        int index) 
    {
        if(index == nums.size()) {
            totalSubsets.push_back(res);
            return;
        }
        res.push_back(nums[index]);
        subsetUtil(nums, res, totalSubsets, index + 1);
        res.pop_back();
        subsetUtil(nums, res, totalSubsets, index + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) { 
        vector<int> res;
        vector<vector<int>> totalSubsets;
        subsetUtil(nums, res, totalSubsets, 0);
        return totalSubsets;
    }
};
