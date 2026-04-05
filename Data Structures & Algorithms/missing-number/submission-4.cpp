class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = n * (n + 1) / 2;
        int currentSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
        }
        return totalSum - currentSum;
    }
};
