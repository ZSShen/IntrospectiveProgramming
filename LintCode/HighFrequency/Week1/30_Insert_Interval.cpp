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
    vector<Interval> insert(vector<Interval> &intervals, Interval curr) {
        // write your code here

        int n = intervals.size();
        if (n == 0) {
            return {curr};
        }

        int l = 0, r = n - 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (curr.start >= intervals[m].start) {
                ++l;
            } else {
                --r;
            }
        }

        const auto& pred = intervals[l];
        const auto& succ = intervals[r];

        if (curr.start < pred.start) {
            intervals.insert(intervals.begin(), curr);
        } else if (curr.start > succ.start) {
            intervals.push_back(curr);
        } else {
            intervals.insert(intervals.begin() + r, curr);
        }

        std::vector<Interval> ans;

        Interval merge(intervals[0]);
        for (int i = 1 ; i <= n ; ++i) {
            if (merge.end >= intervals[i].start) {
                merge.end = std::max(merge.end, intervals[i].end);
                continue;
            }

            ans.push_back(merge);
            merge = intervals[i];
        }
        ans.push_back(merge);

        return ans;
    }
};