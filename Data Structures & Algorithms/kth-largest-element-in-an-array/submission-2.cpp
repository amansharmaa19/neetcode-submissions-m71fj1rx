class Solution {
    priority_queue<int, vector<int>, greater<int>> heap;
public:
    int findKthLargest(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            heap.push(nums[i]);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        return heap.top();
    }
};
