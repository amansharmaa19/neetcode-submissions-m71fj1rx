class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n + 1);
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adjList[u].push_back({v, w});
        }
        vector<int> minDist(n + 1, INT_MAX);
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> pq;
        pq.push({0, k});
        minDist[k] = 0;
        
        while (!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (dist > minDist[node]) {
                continue;
            }
            for (int i = 0; i < adjList[node].size(); i++) {
                int adjacentNode = adjList[node][i].first;
                int currDist = adjList[node][i].second;

                if (dist + currDist < minDist[adjacentNode]) {
                    minDist[adjacentNode] = dist + currDist;
                    pq.push({dist + currDist, adjacentNode});
                }
            }
        }

        int minTime = 0;
        for (int i = 1; i <= n; i++) {
            if (minDist[i] == INT_MAX) {
                return -1;
            }
            minTime = max(minTime, minDist[i]);
        }
        return minTime;
    }
};
