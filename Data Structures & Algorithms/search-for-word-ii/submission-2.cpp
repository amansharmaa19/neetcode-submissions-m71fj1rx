class Solution {
    void dfs(
        int row,
        int col,
        int rows,
        int cols,
        int index,
        vector<vector<char>>& board,
        vector<vector<int>>& vis,
        string word,
        string result,
        bool& found
    ) {
        if (row < 0 || col < 0 || row >= rows || col >= cols
            || vis[row][col] 
            || board[row][col] != word[index]
        ) {
            return;
        }
        vis[row][col] = 1;
        result += board[row][col];
        if (result == word) {
            found = true;
            return;
        }
        dfs(row + 1, col, rows, cols, index + 1, board, vis, word, result, found);
        dfs(row - 1, col, rows, cols, index + 1, board, vis, word, result, found);
        dfs(row, col + 1, rows, cols, index + 1, board, vis, word, result, found);
        dfs(row, col - 1, rows, cols, index + 1, board, vis, word, result, found);
        vis[row][col] = 0; // Backtrack
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int rows = board.size();
        if (rows == 0) {
            return {};
        }
        int cols = board[0].size();
        string result = "";
        vector<string> results;
        for (int k = 0; k < words.size(); k++) {
            bool foundOne = false;
            string word = words[k];
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (board[i][j] == word[0]) {
                        bool found = false;
                        vector<vector<int>> vis(rows, vector<int>(cols, 0));
                        dfs(i, j, rows, cols, 0, board, vis, word, result, found);
                        if (found) {
                            results.push_back(word);
                            foundOne = true;
                            break;
                        }
                    }
                }
                if (foundOne) {
                    break;
                }
            }
        }
        return results;
    }
};
