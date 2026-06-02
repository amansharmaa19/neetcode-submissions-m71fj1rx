class Solution {
    bool partitionUtil(
        int index,
        int sum,
        vector<int>& nums,
        vector<vector<int>>& dp
    ) {
        if (sum == 0) {
            return true;
        }
        if (index == 0) {
            return nums[index] == sum;
        }
        if (dp[index][sum] != -1) {
            return dp[index][sum];
        }
        bool notPick = partitionUtil(index - 1, sum, nums, dp);
        bool pick = false;
        if (nums[index] <= sum) {
            pick = partitionUtil(index - 1, sum - nums[index], nums, dp);
        }
        return dp[index][sum] = pick || notPick;
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        }
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return partitionUtil(n - 1, sum / 2, nums, dp);
    }
};
