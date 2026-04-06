class Solution {
    void traverseIslands(
        int row,
        int col,
        int rows,
        int cols,
        vector<vector<int>>& grid,
        int &currentArea
    ) {
        if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] == 0) {
            return;
        }
        
        grid[row][col] = 0; // Mark the node as visited
        currentArea++;

        traverseIslands(row - 1, col, rows, cols, grid, currentArea);
        traverseIslands(row + 1, col, rows, cols, grid, currentArea);
        traverseIslands(row, col + 1 , rows, cols, grid, currentArea);
        traverseIslands(row, col - 1, rows, cols, grid, currentArea);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) {
            return 0;
        }
        int cols = grid[0].size();
        int currentArea = 0;
        int maxArea = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    currentArea = 0;
                    traverseIslands(i, j, rows, cols, grid, currentArea);
                    maxArea = max(maxArea, currentArea);
                }
            }
        }
        return maxArea;
    }
};
