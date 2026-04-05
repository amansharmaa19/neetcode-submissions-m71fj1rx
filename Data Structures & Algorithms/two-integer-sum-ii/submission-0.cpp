class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> unorderedMap;
        vector<int> twoSumResult;
        for (int i = 0; i < numbers.size(); i++) {
            int key = target - numbers[i];
            if (unorderedMap.contains(key)) {
                twoSumResult.push_back(unorderedMap[key] + 1);
                twoSumResult.push_back(i + 1);
                return twoSumResult;
            } else {
                unorderedMap[numbers[i]] = i;
            }
        }
        return twoSumResult;
    }
};
