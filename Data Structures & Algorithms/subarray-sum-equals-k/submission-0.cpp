class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        hash[0] = 1;
        int sum = 0, totalSubArrays = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (hash.find(sum - k) != hash.end()) {
                totalSubArrays += hash[sum - k];
            }
            hash[sum]++;
        }
        return totalSubArrays;
    }
};