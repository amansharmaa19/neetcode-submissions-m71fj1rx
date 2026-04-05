class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int majority = nums.size() / 3;
        unordered_map<int, int> hashTable;
        unordered_map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); i++) {
            hashTable[nums[i]]++;
        }
        for (it = hashTable.begin(); it != hashTable.end(); it++) {
            if (it->second > majority) {
                result.push_back(it->first);
            }
        }
        return result;
    }
};