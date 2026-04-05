class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());
        if (nums.size() == 0) {
            return result;
        }
        vector<int> prefix(nums.size(), 0);
        vector<int> suffix(nums.size(), 0);
        prefix[0] = 1; 
        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        suffix[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < result.size(); i++) {
            result[i] = prefix[i] * suffix[i];
        }
        return result;
    }
};
 