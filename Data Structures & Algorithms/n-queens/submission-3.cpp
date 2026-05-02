class Solution {
    bool isSafe(int row, int col, int n, vector<string>& board) {
        int i = row, j = col;
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (i = row, j = col; i < n && j < n; i++, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (j = col; j >= 0; j--) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void solve(
        int col,
        int n,
        vector<string>& board,
        vector<vector<string>>& result
    ) {
        if (col == n) {
            result.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, n, board)) {
                board[row][col] = 'Q';
                solve(col + 1, n, board, result);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        solve(0, n, board, result);
        return result;
    }
};
