class Solution {
    bool isSafe(
        vector<vector<int>>& grid,
        int row,
        int col,
        int rows,
        int cols
    ) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == 2 || grid[row][col] == 0) {
            return false;
        }
        return true;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) {
            return -1;
        }
        int cols = grid[0].size();
        bool hasFreshFruits = false;
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    hasFreshFruits = true;
                }
            }
        }

        if (q.empty()) {
            if (hasFreshFruits) {
                return -1;
            }
            return 0;
        }

        int minutes = 0;
        bool isRotten = false;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                pair<int, int> front = q.front();
                int row = front.first;
                int col = front.second;
                q.pop();
                if (isSafe(grid, row + 1, col, rows, cols)) {
                    q.push({row + 1, col});
                    grid[row + 1][col] = 2;
                    isRotten = true;
                }
                if (isSafe(grid, row - 1, col, rows, cols)) {
                    q.push({row - 1, col});
                    grid[row - 1][col] = 2;
                    isRotten = true;
                }
                if (isSafe(grid, row, col + 1, rows, cols)) {
                    q.push({row, col + 1});
                    grid[row][col + 1] = 2;
                    isRotten = true;
                }
                if (isSafe(grid, row, col - 1, rows, cols)) {
                    q.push({row, col - 1});
                    grid[row][col - 1] = 2;
                    isRotten = true;
                }
            }
            if (isRotten) {
                isRotten = false;
                minutes++;
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return minutes;
    }
};
