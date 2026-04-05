class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.empty()) {
            return -1;
        }
        int result = nums[0];
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid - 1] > nums[mid]) {
                return nums[mid];
            }
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};
