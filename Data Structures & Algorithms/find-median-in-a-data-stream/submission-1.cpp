class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            int root = maxHeap.top();
            minHeap.push(root);
            maxHeap.pop();  
        } else if (minHeap.size() > maxHeap.size()) {
            int root = minHeap.top();
            maxHeap.push(root);
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() != minHeap.size()) {
            return (double)(maxHeap.top());
        } else {
            return (double)(maxHeap.top() + minHeap.top()) / 2;
        }
    }
};
