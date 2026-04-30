class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valueToIndex; // Value to index map
        for (int i = 0; i < nums.size(); i++) {
            int currSum = target - nums[i];
            if (valueToIndex.contains(currSum)) {
                return {valueToIndex[currSum], i};
            } else {
                valueToIndex[nums[i]] = i;
            }
        }
        return {};
    }
};
