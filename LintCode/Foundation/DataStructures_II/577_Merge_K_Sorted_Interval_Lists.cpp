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

        int vec_count = intervals.size();
        if (vec_count == 0) {
            return {};
        }

        for (int i = 1 ; i < vec_count ; ++i) {
            while (!intervals[i].empty()) {
                intervals[0].push_back(intervals[i].back());
                intervals[i].pop_back();
            }
        }

        int size = intervals[0].size();
        if (size == 0) {
            return {};
        }

        auto& vec = intervals[0];
        std::sort(vec.begin(), vec.end(),
            [] (const Interval& lhs, const Interval& rhs) {
                if (lhs.start == rhs.start) {
                    return lhs.end < rhs.end;
                }
                return lhs.start < rhs.start;
            });

        std::vector<Interval> ans;
        auto& merge = vec[0];

        for (int i = 1 ; i < size ; ++i) {
            auto& curr = vec[i];

            if (curr.start > merge.end) {
                ans.push_back(merge);

                merge.start = curr.start;
                merge.end = curr.end;
                continue;
            }

            if (curr.end > merge.end) {
                merge.end = curr.end;
            }
        }

        ans.push_back(merge);

        return ans;
    }
};


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


struct Record {
    Interval interval;
    int list_id;
    int offset;

    Record(const Interval& interval, int list_id, int offset)
      : interval(interval),
        list_id(list_id),
        offset(offset)
    { }

    Record& operator=(const Record& rhs) {
        interval = rhs.interval;
        list_id = rhs.list_id;
        offset = rhs.offset;
    }
};


struct RecordCompare {

    bool operator() (const Record& lhs, const Record& rhs) {
        if (lhs.interval.start == rhs.interval.start) {
            return lhs.interval.end > rhs.interval.end;
        }
        return lhs.interval.start > rhs.interval.start;
    }
};


class Solution {
public:
    /**
     * @param intervals: the given k sorted interval lists
     * @return:  the new sorted interval list
     */
    vector<Interval> mergeKSortedIntervalLists(vector<vector<Interval>> &intervals) {
        // write your code here

        int num_list = intervals.size();
        if (num_list == 0) {
            return {};
        }

        std::priority_queue<Record, std::vector<Record>, RecordCompare> queue;
        for (int i = 0 ; i < num_list ; ++i) {
            auto& list = intervals[i];
            if (!list.empty()) {
                queue.push(Record(list[0], i, 0));
            }
        }

        if (queue.empty()) {
            return {};
        }

        std::vector<Interval> ans;

        auto record = queue.top();
        queue.pop();

        auto merge = record.interval;

        // Compensate the queue.
        int list_id = record.list_id;
        int offset = record.offset;
        if (intervals[list_id].size() > offset + 1) {
            queue.push(
                Record(intervals[list_id][offset + 1], list_id, offset + 1));
        }

        while (!queue.empty()) {
            record = queue.top();
            queue.pop();

            auto& curr = record.interval;

            // Compensate the queue.
            list_id = record.list_id;
            offset = record.offset;
            if (intervals[list_id].size() > offset + 1) {
                queue.push(
                    Record(intervals[list_id][offset + 1], list_id, offset + 1));
            }

            if (curr.start > merge.end) {
                ans.push_back(merge);

                merge.start = curr.start;
                merge.end = curr.end;
                continue;
            }

            if (curr.end > merge.end) {
                merge.end = curr.end;
            }
        }

        ans.push_back(merge);

        return ans;
    }
};