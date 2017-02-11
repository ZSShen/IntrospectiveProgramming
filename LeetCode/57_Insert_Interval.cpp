/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool operator< (const Interval& lhs, const Interval& rhs) {
    return lhs.start < rhs.start;
}

bool operator> (const Interval& lhs, const Interval& rhs) {
    return lhs.start > rhs.start;   
}

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        std::vector<Interval> ans;

        int size = intervals.size();
        if (size == 0) {
            ans.push_back(std::move(newInterval));
            return ans;
        }

        // Put the new interval to the proper position.
        int bgn = 0;
        int end = intervals.size() - 1;

        while (bgn < end) {
            int mid = (bgn + end) >> 1;
            if (intervals[mid] > newInterval) {
                end = mid - 1;
            } else {
                bgn = mid + 1;
            }
        }

        if (newInterval > intervals[bgn]) {
            ++bgn;
        }

        intervals.insert(intervals.begin() + bgn, std::move(newInterval));

        // Merge the intervals.
        Interval& mergedInterval = intervals[0];
        for (int i = 1 ; i < intervals.size() ; ++i) {
            Interval& candidate = intervals[i];

            if (candidate.start <= mergedInterval.end &&
                candidate.end > mergedInterval.end) {
                mergedInterval.end = candidate.end;        
                continue;
            }

            if (candidate.start > mergedInterval.end) {
                ans.push_back(std::move(mergedInterval));
                mergedInterval = std::move(candidate);
            }            
        }
        ans.push_back(std::move(mergedInterval));

        return ans;
    }
};