class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, first = 0, second = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero++;
            } else if (nums[i] == 1) {
                first++;
            } else {
                second++;
            }
        } 
        int i = 0;
        while (zero--) {
            nums[i++] = 0;
        }
        while (first--) {
            nums[i++] = 1;
        }
        while (second--) {
            nums[i++] = 2;
        }
    }
};