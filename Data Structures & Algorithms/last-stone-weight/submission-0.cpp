class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (const auto& it : stones) {
            pq.push(it);
        }

        while (!pq.empty()) {
            if (pq.size() == 1) {
                return pq.top();
            }
            int x = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            if (x != y) {
                pq.push(x - y);
            }
        }
        return 0;
    }
};
