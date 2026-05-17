class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto it : nums) {
            if (s.find(it) == s.end()) {
                s.insert(it);
            } else {
                return true;
            }
        }
        return false;
    }
};