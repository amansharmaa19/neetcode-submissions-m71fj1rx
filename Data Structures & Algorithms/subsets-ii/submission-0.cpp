class Solution {
public:

    void subsetUtil(vector<int> &nums, vector<vector<int>> &totalSubsets, vector<int> &res, int index) {
        totalSubsets.push_back(res);

        for (int i = index; i < nums.size(); i++) {

            if (i > index && nums[i] == nums[i-1]) {
                continue;
            }

            res.push_back(nums[i]);
            
            subsetUtil(nums, totalSubsets, res, i + 1);

            res.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> res;
        vector<vector<int>> totalSubsets;
        sort(nums.begin(), nums.end());
        subsetUtil(nums, totalSubsets, res, 0);
        return totalSubsets;
    } 
};
