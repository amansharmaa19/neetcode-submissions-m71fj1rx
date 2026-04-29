class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0) {
            return false;
        }
        int cols = matrix[0].size();
        for (int i = 0; i < rows; i++) {
            int low = 0, high = cols - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (target == matrix[i][mid]) {
                    return true;
                } else if (target <= matrix[i][mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return false;
    }
};
