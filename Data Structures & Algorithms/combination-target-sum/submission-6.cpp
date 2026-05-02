class Solution {
    void combinationSumUtil(
        int index,
        int target,
        vector<int>& nums,
        vector<int>& combination,
        vector<vector<int>>& result
    ) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            if (target < nums[i]) {
                break;
            }
            combination.push_back(nums[i]);
            combinationSumUtil(i, target - nums[i], nums, combination, result);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(nums.begin(), nums.end());
        combinationSumUtil(0, target, nums, combination, result);
        return result;
    }
};
