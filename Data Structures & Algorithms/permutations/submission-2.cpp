class Solution {
    void permuteUtil(
        int index,
        vector<int>& nums,
        vector<vector<int>>& result
    ) {
        if (index == nums.size()) {
            vector<int> permutation;
            for (int i = 0; i < nums.size(); i++) {
                permutation.push_back(nums[i]);
            }
            result.push_back(permutation);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);
            permuteUtil(index + 1, nums, result);
            swap(nums[i], nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteUtil(0, nums, result);
        return result;
    }
};
