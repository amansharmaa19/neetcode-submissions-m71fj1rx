class Solution {
public:
    bool isSafe(vector<string> &board, int &row, int &col, int &n) {
        int i = row, j = col;
        for (i = 0; i < col; i++) {
            if (board[row][i] == 'Q') {
                return false;
            }
        }
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
        return true;
    }

    void solve(int col, vector<string>& board, vector<vector<string>>& result, int &n) {
        if (col == n) {
            result.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, result, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        solve(0, board, result, n);
        return result;
    }
};
