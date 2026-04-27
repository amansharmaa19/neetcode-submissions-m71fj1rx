class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         if (intervals.size() == 0) {
            return 0;
        }
        vector<pair<int, int>> sortedIntervals;
        for (int i = 0; i < intervals.size(); i++) {
            sortedIntervals.push_back({intervals[i][1], intervals[i][0]});
        }
        sort(sortedIntervals.begin(), sortedIntervals.end());

        int prevMeetingEndTime = INT_MIN;
        int minMeetingRooms = 0;
        for (int i = 0; i < sortedIntervals.size(); i++) {
            int startTime = sortedIntervals[i].second;
            int endTime = sortedIntervals[i].first;
            if (startTime >= prevMeetingEndTime) {
                prevMeetingEndTime = endTime;
            } else {
                minMeetingRooms++;
            }
        }
        return minMeetingRooms;
    }
};
