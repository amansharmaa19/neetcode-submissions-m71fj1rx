class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSubArray = INT_MIN;
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        for (int i = 0; i < n; i++) {
            prefix = prefix * nums[i];
            suffix = suffix * nums[n - i - 1];
            maxSubArray = max(maxSubArray, max(prefix, suffix));
            if (prefix == 0) {
                prefix = 1;
            } 
            if (suffix == 0) {
                suffix = 1;
            }
        }
        return maxSubArray;
    }
};
