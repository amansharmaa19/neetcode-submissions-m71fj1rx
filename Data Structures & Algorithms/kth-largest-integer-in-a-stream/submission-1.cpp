class KthLargest {
    int heapSize = 0;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    KthLargest(int k, vector<int>& nums) {
        heapSize = k;
        for (int i = 0; i < nums.size(); i++) {
            minHeap.push(nums[i]);
            if (minHeap.size() > heapSize) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > heapSize) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
