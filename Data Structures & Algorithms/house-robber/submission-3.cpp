class Solution {
    int solve(int index, vector<int>& nums, vector<int>& dp) {
        if (index < 0) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int pick = nums[index] + solve(index - 2, nums, dp);
        int notPick = 0 + solve(index - 1, nums, dp);
        return dp[index] = max(pick, notPick);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int pick = nums[i] + (i - 2 < 0 ? 0 : dp[i - 2]);
            int notPick = 0 + dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        return dp[n - 1];
    }
};
