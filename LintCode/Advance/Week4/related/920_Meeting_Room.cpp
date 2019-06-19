/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        // Write your code here

        int n = intervals.size();
        if (n == 0) {
            return true;
        }

        std::sort(intervals.begin(), intervals.end(),
            [] (const Interval& lhs, const Interval& rhs) {
                if (lhs.start == rhs.start) {
                    return lhs.end < rhs.end;
                }
                return lhs.start < rhs.start;
            }
        );

        int end = intervals[0].end;
        for (int i = 1 ; i < n ; ++i) {
            if (intervals[i].start < end) {
                return false;
            }
            end = intervals[i].end;
        }

        return true;
    }
};