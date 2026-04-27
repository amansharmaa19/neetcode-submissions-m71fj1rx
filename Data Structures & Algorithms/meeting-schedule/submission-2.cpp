/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<pair<int, int>> sortedIntervals;
        for (int i = 0; i < intervals.size(); i++) {
            sortedIntervals.push_back({intervals[i].end, intervals[i].start});
        }
        sort(sortedIntervals.begin(), sortedIntervals.end());

        int prevMeetingEndTime = 0;
        for (int i = 0; i < sortedIntervals.size(); i++) {
            int startTime = sortedIntervals[i].second;
            int endTime = sortedIntervals[i].first;
            if (startTime >= prevMeetingEndTime) {
                prevMeetingEndTime = endTime;
            } else {
                return false;
            }
        }
        return true;
    }
};
