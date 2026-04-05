class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> twoSumResult;
        int i = 0;
        int j = numbers.size() - 1;
        while (i < j) {
            int currentSum = numbers[i] + numbers[j];
            if (currentSum == target) {
                twoSumResult.push_back(i + 1);
                twoSumResult.push_back(j + 1);
                return twoSumResult;
            } else if (currentSum < target) {
                i++;
            } else {
                j--;
            }
        }
        return twoSumResult;
    }
};
