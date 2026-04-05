class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i = 0;
        uint32_t result = 0;
        while (i < 32) {
            result = result << 1;
            result |= n & 1;
            n = n >> 1;
            i++;
        }
        return result;
    }
};
