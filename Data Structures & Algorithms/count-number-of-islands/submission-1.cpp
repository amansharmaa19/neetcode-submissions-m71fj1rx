class Solution {
     void dfs(
        int row,
        int col,
        int rows,
        int cols,
        vector<vector<char>>& adj
    ) {
        if (row < 0 || col < 0 || row >= rows || col >= cols || adj[row][col] == '0') {
            return;
        }

        adj[row][col] = '0'; // Mark this as visited
        
        dfs(row + 1, col, rows, cols, adj);
        dfs(row - 1, col, rows, cols, adj);
        dfs(row, col + 1, rows, cols, adj);
        dfs(row, col - 1, rows, cols, adj);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows == 0) {
            return 0;
        }
        int cols = grid[0].size();
        int totalIslands = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    totalIslands++;
                    dfs(i, j, rows, cols, grid);
                }
            }
        }
        return totalIslands;
    }
};
