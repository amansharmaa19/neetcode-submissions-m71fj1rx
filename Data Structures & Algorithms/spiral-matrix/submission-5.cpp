class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiralOrder;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int up = 0, down = rows - 1;
        int left = 0, right = cols - 1;
        while (left <= right && up <= down) {
            for(int i = left; i <= right; i++) { // left -> right
                spiralOrder.push_back(matrix[up][i]);
            }
            up++;
            for(int i = up; i <= down; i++) { // top -> bottom
                spiralOrder.push_back(matrix[i][right]);
            }
            right--;
            if (up <= down) {
                for (int i = right; i >= left; i--) {
                    spiralOrder.push_back(matrix[down][i]);
                }
                down--;
            }
            if (left <= right) {
                for (int i = down; i >= up; i--) {
                    spiralOrder.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return spiralOrder;
    }
};
