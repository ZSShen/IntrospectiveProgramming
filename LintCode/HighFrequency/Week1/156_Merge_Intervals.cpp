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
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here

        int size = intervals.size();
        if (size == 0) {
            return {};
        }

        std::sort(intervals.begin(), intervals.end(),
            [](const Interval& lhs, const Interval& rhs) {
                if (lhs.start == rhs.end) {
                    return lhs.end < rhs.end;
                }
                return lhs.start < rhs.start;
            });

        std::vector<Interval> ans;
        Interval src(intervals[0]);

        for (int i = 1 ; i < size ; ++i) {
            const auto& dst = intervals[i];
            if (dst.start > src.end) {
                ans.push_back(src);
                src = dst;
                continue;
            }

            src.end = std::max(src.end, dst.end);
        }

        ans.push_back(src);

        return ans;
    }
};
