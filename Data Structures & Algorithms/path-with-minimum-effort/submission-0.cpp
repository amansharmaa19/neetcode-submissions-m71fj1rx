class Solution {
    bool isValid(int row, int col, int rows, int cols) {
        if (row < 0 || col < 0 || row >= rows || col >= cols) {
            return false;
        }
        return true;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        if (rows == 0) {
            return -1;
        }
        int cols = heights[0].size();
        priority_queue<pair<
            int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> minDist(rows, vector<int>(cols, INT_MAX));

        pq.push({0, {0, 0}});
        minDist[0][0] = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            pair<int, pair<int, int>> top = pq.top();
            int dist = top.first;
            int row = top.second.first;
            int col = top.second.second;
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int nr = row + drow[i];
                int nc = col + dcol[i];

                if (isValid(nr, nc, rows, cols)) {
                    int absDiff = abs(heights[row][col] - heights[nr][nc]);
                    int newEffort = max(dist, absDiff);
                    if (newEffort < minDist[nr][nc]) {
                        minDist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return minDist[rows - 1][cols - 1];
    }
};