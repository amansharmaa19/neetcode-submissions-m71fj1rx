class Solution {
public:

    void subsetUtil(vector<int> &nums, vector<vector<int>> &totalSubsets, vector<int> &res, int index) {
        totalSubsets.push_back(res);

        for (int i = index; i < nums.size(); i++) {

            res.push_back(nums[i]);

            subsetUtil(nums, totalSubsets, res, i + 1);

            res.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) { 
        vector<int> res;
        vector<vector<int>> totalSubsets;
        subsetUtil(nums, totalSubsets, res, 0);
        return totalSubsets;
    }
};
