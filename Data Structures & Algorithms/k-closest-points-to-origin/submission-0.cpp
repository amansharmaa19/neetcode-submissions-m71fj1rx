class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if (k == 0 || points.size() == 0) {
            return {};
        }
        vector<vector<int>> result;
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        for (int i = 0; i < points.size(); i++) {
            int key = (points[i][0] * points[i][0]) + 
                (points[i][1] * points[i][1]);
            
            maxHeap.push({key, {points[i][0], points[i][1]}});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        while (!maxHeap.empty()) {
            result.push_back(
                {
                    maxHeap.top().second.first,
                    maxHeap.top().second.second
                }
            );
            maxHeap.pop();
        }
        return result;
    }
};
