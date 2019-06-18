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
     * @param airplanes: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here

        /**
         *
         *          *******
         *
         *            *******
         *
         *      ***
         *
         *    *******************
         *  0 1 2 3 4 5 6 7 8 9 10
         *
         */

        std::vector<Record> records;

        for (const auto& airplane : airplanes) {
            records.push_back(Record(airplane.start, Event::TAKE_OFF));
            records.push_back(Record(airplane.end, Event::LAND));
        }

        std::sort(records.begin(), records.end(),
            [] (const auto& lhs, const auto& rhs) {
                if (lhs.time == rhs.time) {
                    return lhs.type < rhs.type;
                }
                return lhs.time < rhs.time;
            }
        );

        int ans = 0;
        int count = 0;
        for (const auto& record : records) {
            if (record.type == Event::TAKE_OFF) {
                ++count;
            } else {
                --count;
            }
            ans = std::max(ans, count);
        }

        return ans;
    }

private:
    enum Event {
        LAND,
        TAKE_OFF
    };
};
