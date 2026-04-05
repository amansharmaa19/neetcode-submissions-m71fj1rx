class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hashTable;
        for (int i = 0; i < nums.size(); i++) {
            hashTable[nums[i]]++;
        }
        unordered_map<int, int>::iterator it;
        for (it = hashTable.begin(); it != hashTable.end(); it++) {
            if (it->second > 1) {
                return true;
            }
        }
        return false;
    }
};