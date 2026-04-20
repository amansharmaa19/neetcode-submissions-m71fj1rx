class DSU {
    vector<int> parent, rank, size;
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int findUltimateParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        parent[node] = findUltimateParent(parent[node]);
        return parent[node];
    }
    
    void unionByRank(int u, int v) {
        int uParent = findUltimateParent(u);
        int vParent = findUltimateParent(v);
        if (uParent == vParent) {
            return;
        } else if (rank[vParent] < rank[uParent]) {
            parent[vParent] = uParent;
        } else if (rank[uParent] < rank[vParent]) {
            parent[uParent] = vParent;
        } else {
            parent[vParent] = uParent;
            rank[uParent]++;
        }
    }
    
    void unionBySize(int u, int v) {
        int uParent = findUltimateParent(u);
        int vParent = findUltimateParent(v);
        if (uParent == vParent) {
            return;
        } else if (size[uParent] < size[vParent]) {
            parent[uParent] = vParent;
            size[vParent] += size[uParent];
        } else {
            parent[vParent] = uParent;
            size[uParent] += size[vParent];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size() + 1);
        int redundantStart = -1, redundantEnd = -1;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (dsu.findUltimateParent(u) != dsu.findUltimateParent(v)) {
                dsu.unionBySize(u, v);
            } else {
                redundantStart = u;
                redundantEnd = v;
            }
        }
        return {redundantStart, redundantEnd};
    }
};
