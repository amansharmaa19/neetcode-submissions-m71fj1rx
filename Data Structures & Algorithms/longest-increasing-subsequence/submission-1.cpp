class Solution {
    int lisUtil(
        int index,
        int prev,
        vector<int>& nums,
        vector<vector<int>>& dp
    ) {
        if (index == nums.size()) {
            return 0;
        }
        if (dp[index][prev + 1] != -1) {
            return dp[index][prev + 1];
        }
        int notPick = lisUtil(index + 1, prev, nums, dp);
        int pick = INT_MIN;
        if (prev == -1 || nums[index] > nums[prev]) {
            pick =  1 + lisUtil(index + 1, index, nums, dp);
        }
        return dp[index][prev + 1] = max(pick, notPick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return lisUtil(0, -1, nums, dp);
    }
};
