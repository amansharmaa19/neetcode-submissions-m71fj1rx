class Solution {
public:
    bool isSafe(vector<string>& board, int& col, int& row, int& n) {
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i < n && j < n; i++, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void solve(vector<string>& board, int col, int &n, int& result) {
        if (col == n) {
            result++;
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(board, col, row, n)) {
                board[row][col] = 'Q';
                solve(board, col + 1, n, result);
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        int result = 0;
        vector<string> board(n, string(n, '.'));
        solve(board, 0, n, result);
        return result;
    }
};