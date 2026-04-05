class Solution {
public:
    int hammingWeight(uint32_t n) {
        int totalOnes = 0;
        int i = 0;
        int leftShift = 1;
        while (i < 32) {
            if ((leftShift << i) & n) {
                totalOnes++;
            }
            i++;
        }
        return totalOnes;
    }
};
