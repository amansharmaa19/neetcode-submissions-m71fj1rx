class Solution {
    void checkRegion(
        int row,
        int col,
        int rows,
        int cols,
        vector<vector<char>>& board,
        vector<vector<int>>& vis
    ) {
        if (row < 0 || col < 0 || row >= rows || col >= cols || vis[row][col] == 1 || board[row][col] != 'O') {
            return;
        }

        vis[row][col] = 1;
    
        checkRegion(row + 1, col, rows, cols, board, vis);
        checkRegion(row - 1, col, rows, cols, board, vis);
        checkRegion(row, col + 1, rows, cols, board, vis);
        checkRegion(row, col - 1, rows, cols, board, vis);
    }
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if (rows == 0) {
            return;
        }
        int cols = board[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        
        // Left -> Right
        for (int i = 0; i < cols; i++) {
            if (board[0][i] == 'O') {
                checkRegion(0, i, rows, cols, board, vis);
            }
        }
        
        // Top -> bottom
        for (int i = 0; i < rows; i++) {
            if (board[i][cols - 1] == 'O') {
                checkRegion(i, cols - 1, rows, cols, board, vis);
            }
        }

        // Right to left
        for (int i = cols - 1; i >= 0; i--) {
            if (board[rows - 1][i] == 'O') {
                checkRegion(rows - 1, i, rows, cols, board, vis);
            }
        }
        
        // Bottom to top
        for (int i = rows - 1; i >= 0; i--) {
            if (board[i][0] == 'O') {
                checkRegion(i, 0, rows, cols, board, vis);
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (vis[i][j] != 1) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
