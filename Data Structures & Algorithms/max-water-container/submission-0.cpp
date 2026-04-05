class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mostWater = 0;
        int left = 0;
        int right = heights.size() - 1;
        while (left < right) {
            int width = right - left;
            int height = min(heights[left], heights[right]);
            int currentWater = width * height;
            mostWater = max(mostWater, currentWater);
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return mostWater;
    }
};
