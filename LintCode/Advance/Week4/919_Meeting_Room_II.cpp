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
    char type;

    Record(int time, char type)
      : time(time), type(type)
    { }
};


class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here

        /**
         *
         *      ****  ****
         *
         *  *******************
         *
         *  00 05 10 15 20 25 30
         *
         */

        std::vector<Record> records;
        for (const auto& interval : intervals) {
            records.push_back(Record(interval.start, Type::BGN));
            records.push_back(Record(interval.end, Type::END));
        }

        std::sort(records.begin(), records.end(),
            [] (const auto& lhs, const auto& rhs) {
                if (lhs.time == rhs.time) {
                    return lhs.type < rhs.type;
                }
                return lhs.time < rhs.time;
            }
        );

        int count = 0;
        int ans = 0;

        for (const auto& record : records) {
            if (record.type == Type::BGN) {
                ++count;
                ans = std::max(ans, count);
            } else {
                --count;
            }
        }

        return ans;
    }

private:
    enum Type {
        END,
        BGN
    };
};