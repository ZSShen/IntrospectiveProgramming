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

        int n = intervals.size();
        if (n == 0) {
            return {};
        }

        std::sort(intervals.begin(), intervals.end(),
            [] (const auto& lhs, const auto& rhs) {
                return lhs.start < rhs.start;
            });

        std::vector<Interval> ans;
        Interval merge(intervals[0]);

        for (int i = 1 ; i < n ; ++i) {
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