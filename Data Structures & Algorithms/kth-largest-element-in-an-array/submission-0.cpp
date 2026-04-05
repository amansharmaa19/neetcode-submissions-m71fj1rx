class Solution {
    priority_queue<int> heap;
public:
    int findKthLargest(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            heap.push(nums[i]);
        }
        int count = k - 1;
        while(count--) {
            heap.pop();
        }
        return heap.top();
    }
};
