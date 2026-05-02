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
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }
            combination.push_back(nums[i]);
            combinationSumUtil(i + 1, target - nums[i], nums, combination, result);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        combinationSumUtil(0, target, candidates, combination, result);
        return result;
    }
};
