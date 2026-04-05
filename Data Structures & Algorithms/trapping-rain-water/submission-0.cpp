class Solution {
public:
    int trap(vector<int>& height) {
        int totalElements = height.size();
        vector<int> leftMaxElements(totalElements, 0);
        vector<int> rightMaxElements(totalElements, 0);
        int currentMax = 0;
        int totalWaterTrapped = 0;
        for (int i = 0; i < totalElements; i++) {
            if (height[i] > currentMax) {
                currentMax = height[i];
            }
            leftMaxElements[i] = currentMax;
        }
        currentMax = 0;
        for (int i = totalElements - 1; i >= 0; i--) {
            if (height[i] > currentMax) {
                currentMax = height[i];
            }
            rightMaxElements[i] = currentMax;
        }
        for(int i = 0; i < totalElements; i++) {
            totalWaterTrapped += min(leftMaxElements[i], rightMaxElements[i]) - height[i];
        }
        return totalWaterTrapped;
    }
};
