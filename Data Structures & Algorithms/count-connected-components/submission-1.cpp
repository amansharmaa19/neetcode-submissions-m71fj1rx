class Solution {
    void travereComponents(
        int start,
        vector<vector<int>>& adj,
        vector<int>& vis
    ) {
        vis[start] = 1;

        for (int i = 0; i < adj[start].size(); i++) {
            int element = adj[start][i];
            if (!vis[element]) {
                travereComponents(element, adj, vis);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n);
        int components = 0;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                components++;
                travereComponents(i, adj, vis);
            }
        }
        return components;
    }
};
