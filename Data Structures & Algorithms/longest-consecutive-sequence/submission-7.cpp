class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        unordered_set<int> s(nums.begin(), nums.end());
        int maxCount = 1;
        for (auto val : s) {
            if (!s.contains(val - 1)) {
                int count = 1;
                while (s.contains(val + 1)) {
                    val++;
                    count++;
                    maxCount = max(maxCount, count);
                }
            }
        }
        return maxCount;
    }
};
