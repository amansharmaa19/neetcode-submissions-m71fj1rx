class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        int prefix = 1;
        for (int i = 1; i < result.size(); i++) {
            prefix *= nums[i - 1];
            result[i] *= prefix;
        }
        int suffix = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            suffix *= nums[i + 1];
            result[i] *= suffix;
        }
        return result;
    }
};
 