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
     * @param intervals: the given k sorted interval lists
     * @return:  the new sorted interval list
     */
    vector<Interval> mergeKSortedIntervalLists(vector<vector<Interval>> &intervals) {
        // write your code here

        int size = intervals.size();
        if (size == 0) {
            return {};
        }

        return runKWayMerge(intervals, 0, size - 1);
    }

private:
    std::vector<Interval> runKWayMerge(
            const std::vector<std::vector<Interval>>& intervals,
            int l,
            int r) {

        if (l == r) {
            return intervals[l];
        }

        int m = (l + r) >> 1;
        auto src = runKWayMerge(intervals, l, m);
        auto dst = runKWayMerge(intervals, m + 1, r);
        return mergeTwoIntervals(src, dst);
    }

    std::vector<Interval> mergeTwoIntervals(
            const std::vector<Interval>& src,
            const std::vector<Interval>& dst) {

        int size_src = src.size();
        int size_dst = dst.size();

        if (size_src == 0 && size_dst == 0) {
            return {};
        }
        if (size_src == 0) {
            return dst;
        }
        if (size_dst == 0) {
            return src;
        }

        // Determine the initial setting of the current interval.
        Interval current;
        int i, j;
        if (src[0].start < dst[0].start) {
            current.start = src[0].start;
            current.end = src[0].end;
            i = 1;
            j = 0;
        } else {
            current.start = dst[0].start;
            current.end = dst[0].end;
            i = 0;
            j = 1;
        }

        std::vector<Interval> collect;

        while (i < size_src && j < size_dst) {
            if (src[i].start < dst[j].start) {
                merge(current, src[i++], collect);
            } else {
                merge(current, dst[j++], collect);
            }
        }

        while (i < size_src) {
            merge(current, src[i++], collect);
        }
        while (j < size_dst) {
            merge(current, dst[j++], collect);
        }

        collect.push_back(current);
        return collect;
    }

    void merge(
            Interval& current,
            const Interval& to_be_merged,
            std::vector<Interval>& collect) {

        if (to_be_merged.start > current.end) {
            collect.push_back(current);
            current.start = to_be_merged.start;
            current.end = to_be_merged.end;
            return;
        }

        current.end = std::max(current.end, to_be_merged.end);
    }
};
