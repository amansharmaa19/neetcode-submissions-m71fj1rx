class Solution {
public:
    void combinationUtil(
        vector<int>& nums,
        int target,
        int index,
        vector<int> &eachCombination,
        vector<vector<int>> &combinations
    ) {
        if (target == 0) {
            combinations.push_back(eachCombination);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            // if (i > index && nums[i] == nums[i - 1]) {
            //     continue;
            // }
            if (nums[i] > target) {
                break;
            }
            eachCombination.push_back(nums[i]);
            combinationUtil(
                nums,
                target - nums[i],
                i,
                eachCombination,
                combinations
            );
            eachCombination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> combinations;
        vector<int> eachCombination;
        combinationUtil(nums, target, 0, eachCombination, combinations);
        return combinations;
    }
};
