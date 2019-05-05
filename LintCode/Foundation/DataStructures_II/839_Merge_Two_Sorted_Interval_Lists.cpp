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

        while (!list2.empty()) {
            list1.push_back(list2.back());
            list2.pop_back();
        }

        if (list1.empty()) {
            return {};
        }

        std::sort(list1.begin(), list1.end(),
            [] (const Interval& lhs, const Interval& rhs) {
                if (lhs.start == rhs.start) {
                    return lhs.end < rhs.end;
                }
                return lhs.start < rhs.start;
            });

        std::vector<Interval> ans;

        int size = list1.size();
        auto& merge = list1[0];
        for (int i = 1 ; i < size ; ++i) {
            auto& curr = list1[i];

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