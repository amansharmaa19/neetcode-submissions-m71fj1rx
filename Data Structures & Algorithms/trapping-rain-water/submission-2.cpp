class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) {
            return 0;
        }
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int waterTrapped = 0;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (leftMax < rightMax) {
                waterTrapped += leftMax - height[left];
                left++;
            } else {
                waterTrapped += rightMax - height[right];
                right--;
            }
        } 
        return waterTrapped;
    }
};
