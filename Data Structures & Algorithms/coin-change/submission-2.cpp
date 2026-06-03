class Solution {
    int coinChangeUtil(
        int index, 
        int target,
        vector<int>& coins,
        vector<vector<int>>& dp
    ) {
        if (index == 0) {
            if (target % coins[index] == 0) {
                return target/coins[index];
            }
            return 1e9;
        }
        if (dp[index][target] != -1) {
            return dp[index][target];
        }
        int notPick = coinChangeUtil(index - 1, target, coins, dp);
        int pick = 1e9;
        if (coins[index] <= target) {
            pick = 1 + coinChangeUtil(index, target - coins[index], coins, dp);
        }
        return dp[index][target] = min(pick, notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = coinChangeUtil(n - 1, amount, coins, dp);
        return ans == 1e9 ? -1 : ans;
    }
};
