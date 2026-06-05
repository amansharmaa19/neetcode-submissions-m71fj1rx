class Solution {
public:
    int targetSumUtil(
        int index,
        int sum,
        vector<int>& arr,
        vector<vector<int>>& dp
    ) {
        if (index == 0) {
            if (sum == 0 && arr[index] == 0) {
                return 2;
            }
            if (sum == 0 || arr[index] == sum) {
                return 1;
            }
            return 0;
        }
        if (dp[index][sum] != -1) {
            return dp[index][sum];
        }
        int notPick = targetSumUtil(index - 1, sum, arr, dp);
        int pick = false;
        if (arr[index] <= sum) {
            pick = targetSumUtil(index - 1, sum - arr[index], arr, dp);
        }
        return dp[index][sum] = pick + notPick;
    }

    int findTargetSumWays(vector<int>& arr, int target) {
        // code here
        int totalSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            totalSum += arr[i];
        }
        if (totalSum - target < 0 || (totalSum - target) % 2 != 0) {
            return 0;
        }
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));
        return targetSumUtil(n - 1, (totalSum - target) / 2, arr, dp);
    }
};
