class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        for (int i = 0; i < rows; i++) {
            int columns = matrix[0].size() - 1;
            int low = 0;
            int high = columns;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (matrix[i][mid] == target) {
                    return true;
                } else if (target < matrix[i][mid]) {
                    high = mid -1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return false;
    }
};
