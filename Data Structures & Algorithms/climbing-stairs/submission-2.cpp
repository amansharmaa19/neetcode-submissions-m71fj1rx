class Solution {
    int climbStairsUtil(int n, vector<int>& dp) {
        if (n == 0 || n == 1) {
            return 1;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = climbStairsUtil(n - 1, dp) + climbStairsUtil(n - 2, dp);
    }

public:
    int climbStairs(int n) {
        int first = 1, second = 1;
        for (int i = 2; i <= n; i++) {
            int currSum = first + second;
            second = first;
            first = currSum;
        }
        return first;
    }
};
