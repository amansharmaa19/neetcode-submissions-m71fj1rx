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
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size() == 0) {
            return 0;
        }
        int minMeetingRooms = 0;
        vector<pair<int, int>> sortedIntervals;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i < intervals.size(); i++) {
            sortedIntervals.push_back({intervals[i].start, intervals[i].end});
        }
        sort(sortedIntervals.begin(), sortedIntervals.end());
        minHeap.push(sortedIntervals[0].second);
        minMeetingRooms = 1;

        for (int i = 1; i < sortedIntervals.size(); i++) {
            int start = sortedIntervals[i].first;
            int end = sortedIntervals[i].second;
            while (!minHeap.empty() && start >= minHeap.top()) {
                minHeap.pop();
            } 
            minHeap.push(sortedIntervals[i].second);
            minMeetingRooms = max(minMeetingRooms, (int) minHeap.size());
        }
        return minMeetingRooms;
    }
};
