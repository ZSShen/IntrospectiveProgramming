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
     * @param list1: one of the given list
     * @param list2: another list
     * @return: the new sorted list of interval
     */
    vector<Interval> mergeTwoInterval(vector<Interval> &list1, vector<Interval> &list2) {
        // write your code here

        std::vector<Interval> ans;

        int size_1 = list1.size();
        int size_2 = list2.size();
        if (size_1 == 0 && size_2 == 0) {
            return ans;
        }

        int index_1, index_2;
        Interval interval;
        if (list1[0].start < list2[0].start) {
            index_1 = 1;
            index_2 = 0;
            interval.start = list1[0].start;
            interval.end = list1[0].end;
        } else {
            index_1 = 0;
            index_2 = 1;
            interval.start = list2[0].start;
            interval.end = list2[0].end;
        }

        while (index_1 < size_1 && index_2 < size_2) {
            if (list1[index_1].start < list2[index_2].start) {
                merge(interval, list1[index_1], ans);
                ++index_1;
            } else {
                merge(interval, list2[index_2], ans);
                ++index_2;
            }
        }

        while (index_1 < size_1) {
            merge(interval, list1[index_1], ans);
            ++index_1;
        }
        while (index_2 < size_2) {
            merge(interval, list2[index_2], ans);
            ++index_2;
        }

        ans.push_back(interval);
        return ans;
    }

private:
    void merge(
            Interval& current,
            Interval& to_be,
            std::vector<Interval>& ans) {

        if (to_be.start <= current.end) {
            current.end = std::max(to_be.end, current.end);
            return;
        }

        ans.push_back(current);
        current.start = to_be.start;
        current.end = to_be.end;
    }
};