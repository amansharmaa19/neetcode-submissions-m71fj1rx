class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int i = 0; i <= n; i++) {
            totalSum = totalSum ^ i;
        }
        int currentSum = 0;
        for (int i = 0; i < n; i++) {
            currentSum = currentSum ^ nums[i];
        }
        return totalSum ^ currentSum;
    }
};
