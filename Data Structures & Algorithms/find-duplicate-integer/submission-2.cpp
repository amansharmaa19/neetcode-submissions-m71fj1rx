class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int currentIndex = abs(nums[i]);
            if (nums[currentIndex] < 0) {
                return abs(nums[i]);
            }
            nums[currentIndex] *= -1;
        }
        return -1;
    }
};
