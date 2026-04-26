class Solution {
    int solve(int start, int end, vector<int>& nums, vector<int>& dp) {
        if (start < end) {
            return 0;
        }
        if (dp[start] != -1) {
            return dp[start];
        }
        int pick = nums[start] + solve(start - 2, end, nums, dp);
        int notPick = 0 + solve(start - 1, end, nums, dp);
        return dp[start] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> dp(nums.size(), -1);
        vector<int> dp1(nums.size(), -1);
        return max(solve(nums.size() - 2, 0, nums, dp), solve(nums.size() - 1, 1, nums, dp1));
    }
};

// 3, 4, 3
