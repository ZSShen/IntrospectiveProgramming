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
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here

        int n = intervals.size();
        if (n == 0) {
            return {newInterval};
        }

        int l = 0, r = n - 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (newInterval.start <= intervals[m].start) {
                r = m;
            } else {
                l = m;
            }
        }

        // Compare the beginning timestamp.
        auto iter = intervals.begin();
        if (newInterval.start < intervals[l].start) {
            intervals.insert(iter + l, newInterval);
        } else if (intervals[r].start < newInterval.start) {
            intervals.insert(iter + r + 1, newInterval);
        } else {
            intervals.insert(iter + r, newInterval);
        }

        std::vector<Interval> ans;
        Interval merge(intervals[0]);

        for (int i = 1 ; i <= n ; ++i) {
            const auto& curr = intervals[i];

            if (curr.start <= merge.end) {
                merge.end = std::max(merge.end, curr.end);
                continue;
            }

            ans.emplace_back(std::move(merge));
            merge = curr;
        }
        ans.emplace_back(std::move(merge));

        return ans;
    }
};