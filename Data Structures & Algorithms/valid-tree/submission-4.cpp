class Solution {
    bool detectCycle(
        int start,
        int parent,
        vector<vector<int>>& adj,
        vector<int>& vis
    ) {
        vis[start] = 1;
        for (int i = 0; i < adj[start].size(); i++) {
            int neighbour = adj[start][i];
            if (!vis[neighbour]) {
                if (detectCycle(neighbour, start, adj, vis)) {
                    return true;
                }
            } else if (parent != neighbour) {
                return true;
            }
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        bool isValid = true;
        vector<int> vis(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (detectCycle(0, -1, adj, vis)) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                return false;
            }
        }
        return true;
    }
};