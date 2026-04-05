class Solution {
public:
    int trap(vector<int>& height) {
        int totalWaterTrapped = 0;
        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (left < right) {
            leftMax = max(height[left], leftMax);
            rightMax = max(height[right], rightMax);
            if (leftMax < rightMax) {
                totalWaterTrapped += leftMax - height[left];
                left++;
            } else {
                totalWaterTrapped += rightMax - height[right];
                right--;
            }
        }
        return totalWaterTrapped;
    }
};
