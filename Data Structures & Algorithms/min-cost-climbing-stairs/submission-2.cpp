class Solution {
    int minCostUtil(int n, vector<int>& cost, vector<int>& dp) {
        if (n == 0) {
            return cost[0];
        } 
        if (n == 1) {
            return cost[1];
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        int left = minCostUtil(n - 1, cost, dp);
        int right = minCostUtil(n - 2, cost, dp);
        return dp[n] = cost[n] + min(left, right);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};
