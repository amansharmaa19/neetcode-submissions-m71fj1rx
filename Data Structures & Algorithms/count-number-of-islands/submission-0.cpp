class Solution {
     void dfs(
        int row,
        int col,
        int rows,
        int cols,
        vector<vector<int>>& vis,
        vector<vector<char>>& adj
    ) {
        if (row < 0 || col < 0 || row >= rows || col >= cols || adj[row][col] == '0' || vis[row][col] == 1) {
            return;
        }

        vis[row][col] = 1; // Mark this as visited
        
        dfs(row + 1, col, rows, cols, vis, adj);
        dfs(row - 1, col, rows, cols, vis, adj);
        dfs(row, col + 1, rows, cols, vis, adj);
        dfs(row, col - 1, rows, cols, vis, adj);
        // dfs(row + 1, col + 1, rows, cols, vis, adj);
        // dfs(row - 1, col + 1, rows, cols, vis, adj);
        // dfs(row + 1, col - 1, rows, cols, vis, adj);
        // dfs(row - 1, col - 1, rows, cols, vis, adj);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows == 0) {
            return 0;
        }
        int cols = grid[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        int totalIslands = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (vis[i][j] == 0 && grid[i][j] == '1') {
                    totalIslands++;
                    dfs(i, j, rows, cols, vis, grid);
                }
            }
        }
        return totalIslands;
    }
};
