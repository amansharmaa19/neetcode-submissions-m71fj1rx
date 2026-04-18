class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjList(n);
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            adjList[u].push_back({v, w});
        }
        vector<int> minDist(n, INT_MAX);
        queue<pair<int, int>> q;
        q.push({src, 0});
        minDist[src] = 0;

        int stops = 0;
        while (!q.empty() && stops <= k) {
            int size = q.size();
            while (size--) {
                int node = q.front().first;
                int dist = q.front().second;
                q.pop();
                for (int i = 0; i < adjList[node].size(); i++) {
                    int adjacentNode = adjList[node][i].first;
                    int currDist = adjList[node][i].second;
                    if (currDist + dist < minDist[adjacentNode]) {
                        minDist[adjacentNode] = currDist + dist;
                        q.push({adjacentNode, minDist[adjacentNode]});
                    }
                }
            }
            stops++;
        }
        if (minDist[dst] != INT_MAX) {
            return minDist[dst];
        }
        return -1;
    }
};
