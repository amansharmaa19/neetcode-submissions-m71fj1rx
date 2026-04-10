class Solution {
    bool isValid(int row, int col, int rows, int cols, vector<vector<int>>& grid) {
        if (row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] != INT_MAX) {
            return false;
        }
        return true;
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) {
            return;
        }
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int current = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                pair<int, int> front = q.front();
                q.pop();
                int row = front.first;
                int col = front.second;
                if (isValid(row + 1, col, rows, cols, grid)) {
                    grid[row + 1][col] = current;
                    q.push({row + 1, col});
                }
                if (isValid(row - 1, col, rows, cols, grid)) {
                    grid[row - 1][col] = current;
                    q.push({row - 1, col});
                }
                if (isValid(row, col + 1, rows, cols, grid)) {
                    grid[row][col + 1] = current;
                    q.push({row, col + 1});
                }
                if (isValid(row, col - 1, rows, cols, grid)) {
                    grid[row][col - 1] = current;
                    q.push({row, col - 1});
                }
            }
            current++;
        }
    }
};
