class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSubArray = INT_MIN;
        int n = nums.size();
        int currSum = 0;
        for (int i = 0; i < n; i++) {
            currSum += nums[i];
            maxSubArray = max(maxSubArray, currSum);
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSubArray;
    }
};
