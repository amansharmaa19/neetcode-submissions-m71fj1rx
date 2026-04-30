class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftPrefix(nums.size(), 1);
        vector<int> rightPrefix(nums.size(), 1);
        vector<int> result(nums.size(), 0);
        for (int i = 1; i < nums.size(); i++) {
            leftPrefix[i] = leftPrefix[i - 1] * nums[i - 1];
        }
        for (int i = nums.size() - 2; i >= 0; i--) {
            rightPrefix[i] = rightPrefix[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < nums.size(); i++) {
            result[i] = leftPrefix[i] * rightPrefix[i];
        }
        return result;
    }
};
