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
    vector<Interval> merge(vector<Interval>& intervals)
    {
        vector<Interval> new_intervals;
        int count = intervals.size();
        if (count == 0)
            return new_intervals;

        sort(intervals.begin(), intervals.end(), comparator_);

        int idx = 0;
        new_intervals.push_back(intervals[idx++]);

        int top = 0;
        while (idx < count) {
            Interval& inter_new = intervals[idx];
            Interval& inter_curr = new_intervals[top];

            if (inter_new.start <= inter_curr.end) {
                if (inter_new.end > inter_curr.end)
                    inter_curr.end = inter_new.end;
            }
            else {
                new_intervals.push_back(inter_new);
                ++top;
            }
            ++idx;
        }
        return new_intervals;
    }

private:
    struct IntervalComparator
    {
        bool operator() (Interval& src, Interval& tge)
        {
            return src.start < tge.start;
        }
    } comparator_;

};