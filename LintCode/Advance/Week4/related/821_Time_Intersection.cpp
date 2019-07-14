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
    int time;
    char event;

    Record(int time, char event)
      : time(time), event(event)
    { }
};


class Solution {
public:
    /**
     * @param seqA: the list of intervals
     * @param seqB: the list of intervals
     * @return: the time periods
     */
    vector<Interval> timeIntersection(vector<Interval> &seqA, vector<Interval> &seqB) {
        // Write your code here

        /**
         *  ***********
         *
         *  ***     **************
         *
         *  1 2 3 4 5 6 ... ... 100
         */

        std::vector<Record> recs;

        for (const auto& seq : seqA) {
            recs.push_back(Record(seq.start, Event::LOG_IN));
            recs.push_back(Record(seq.end, Event::LOG_OUT));
        }
        for (const auto& seq : seqB) {
            recs.push_back(Record(seq.start, Event::LOG_IN));
            recs.push_back(Record(seq.end, Event::LOG_OUT));
        }

        std::sort(recs.begin(), recs.end(),
            [] (const auto& lhs, const auto& rhs) {
                if (lhs.time == rhs.time) {
                    return lhs.event < rhs.event;
                }
                return lhs.time < rhs.time;
            }
        );

        std::vector<Interval> ans;
        Interval interval;
        int count = 0;

        for (const auto& rec : recs) {
            if (rec.event == Event::LOG_IN) {
                ++count;
                if (count == 2) {
                    interval.start = rec.time;
                }
            } else {
                if (count == 2) {
                    interval.end = rec.time;
                    ans.push_back(interval);
                }
                --count;
            }
        }

        return ans;
    }

private:
    enum Event {
        LOG_OUT,
        LOG_IN
    };
};