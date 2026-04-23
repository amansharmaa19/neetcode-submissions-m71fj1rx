class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxB = 0;
        for (int i = 0; i < piles.size(); i++) {
            maxB = max(maxB, piles[i]);
        }
        int left = 1, right = maxB;
        while (left <= right) {
            int totalHours = 0;
            int mid = (left + right) / 2;
            for (int j = 0; j < piles.size(); j++) {
                totalHours += ceil((double)piles[j] / mid); 
            }
            if (totalHours <= h) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
