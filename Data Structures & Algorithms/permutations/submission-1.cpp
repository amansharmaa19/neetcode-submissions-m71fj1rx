class Solution {
public:
    void permuteUtil(
        vector<int> &nums,
        vector<vector<int>> &res,
        int index
    ) {
        if (index == nums.size() - 1) {
            vector<int> temp;
            for (int i = 0; i < nums.size(); i++) {
                temp.push_back(nums[i]);
            }
            res.push_back(temp);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            permuteUtil(nums, res, index + 1);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteUtil(nums, result, 0);
        return result;
    }
};
