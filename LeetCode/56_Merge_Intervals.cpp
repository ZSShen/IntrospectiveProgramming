/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {

        std::vector<Interval> merge;
        int count = intervals.size();
        if (count == 0) {
            return merge;
        }

        std::sort(intervals.begin(), intervals.end(),
                  [] (const Interval& lhs, const Interval& rhs) {
            return lhs.start < rhs.start;
        });

        Interval range(intervals[0].start, intervals[0].end);
        int index = 1;
        while (index < count) {
            if (intervals[index].start <= range.end) {
                if (intervals[index].end > range.end) {
                    range.end = intervals[index].end;
                }
            } else {
                merge.push_back(range);
                range.start = intervals[index].start;
                range.end = intervals[index].end;
            }
            ++index;
        }

        // Last shot.
        merge.push_back(range);

        return merge;
    }
};