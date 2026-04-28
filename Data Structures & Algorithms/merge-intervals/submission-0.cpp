class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> totalIntervals;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        totalIntervals.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            int lastIndex = totalIntervals.size() - 1;
            if (totalIntervals[lastIndex][1] < intervals[i][0]) {
                totalIntervals.push_back(intervals[i]);
            } else {
                totalIntervals[lastIndex][0] 
                    = min(totalIntervals[lastIndex][0], intervals[i][0]);
                totalIntervals[lastIndex][1] 
                    = max(totalIntervals[lastIndex][1], intervals[i][1]);
            }
        }
        return totalIntervals;
    }
};
