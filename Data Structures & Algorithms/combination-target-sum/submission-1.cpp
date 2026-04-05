class Solution {
public:
    void combinationUtil(
        vector<int>& nums,
        int target,
        int index,
        vector<int> &eachCombination,
        vector<vector<int>> &combinations
    ) {
        if (index == nums.size()) {
            if (target == 0) {
                combinations.push_back(eachCombination);
            }
            return;
        }
        if (nums[index] <= target) {
            eachCombination.push_back(nums[index]);
            combinationUtil(
                nums,
                target - nums[index],
                index,
                eachCombination,
                combinations
            );
            eachCombination.pop_back();
        }
        combinationUtil(
            nums,
            target,
            index + 1,
            eachCombination,
            combinations
        );
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> combinations;
        vector<int> eachCombination;
        combinationUtil(nums, target, 0, eachCombination, combinations);
        return combinations;
    }
};
