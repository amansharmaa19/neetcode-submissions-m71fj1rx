class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> mySet;
        set<int>::iterator it;
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            mySet.insert(nums[i]);
        }
        int start = INT_MIN;
        int count = 0;
        for (it = mySet.begin(); it != mySet.end(); it++) {
            if (start == INT_MIN) {
                start = *it;
                count++;
                result = max(result, count);
            } else if (*it == (start + 1)) {
                count++;
                start = *it;
                result = max(result, count);
            } else {
                start = *it;
                count = 1; 
            }
        }
        return result;
    }
};
