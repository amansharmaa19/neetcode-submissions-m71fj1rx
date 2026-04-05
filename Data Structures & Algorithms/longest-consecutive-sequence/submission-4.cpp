class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int lcs = 0;
        for (int num : s) {
            if (s.find(num - 1) == s.end()) {
                int count = 1;
                int currNum = num;
                while (s.find(currNum + 1) != s.end()) {
                    count++;
                    currNum++;
                }
                lcs = max(lcs, count);
            }
        }
        return lcs;
    }
};
