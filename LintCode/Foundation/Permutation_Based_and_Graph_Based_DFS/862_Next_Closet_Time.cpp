class Solution {
public:
    /**
     * @param time: the given time
     * @return: the next closest time
     */
    string nextClosestTime(string &time) {
        // write your code here

        std::unordered_set<char> cands;
        cands.insert(time[0]);
        cands.insert(time[1]);
        cands.insert(time[3]);
        cands.insert(time[4]);

        std::string copy(time);
        char* buf = const_cast<char*>(copy.c_str());
        buf[2] = 0;

        int hour = atoi(buf);
        int minute = atoi(buf + 3);
        int timestamp = hour * 60 + minute;
        int diff = std::numeric_limits<int>::max();

        std::string ans(time);
        runBacktracking(0, 5, cands, hour, minute, timestamp, diff, buf, ans);
        return ans;
    }

private:
    void runBacktracking(
            int idx,
            int bnd,
            std::unordered_set<char>& cands,
            int hour,
            int minute,
            int timestamp,
            int& diff,
            char* buf,
            std::string& ans) {

        if (idx == bnd) {

            // Check legal timestamps.
            int new_hour = atoi(buf);
            if (new_hour >= 24) {
                return;
            }

            int new_minute = atoi(buf + 3);
            if (new_minute >= 60) {
                return;
            }

            int new_timestamp = new_hour * 60 + new_minute;
            if (new_timestamp == timestamp) {
                return;
            }

            // Check the distance between 2 time points.
            int new_diff;
            if (new_timestamp > timestamp) {
                new_diff = new_timestamp - timestamp;
            } else {
                new_diff = new_timestamp + (1440 - timestamp);
            }

            if (new_diff < diff) {
                diff = new_diff;
                buf[2] = ':';
                ans = buf;
                buf[2] = 0;
            }

            return;
        }

        for (char cand : cands) {
            buf[idx] = cand;

            if (idx == 1) {
                runBacktracking(
                    idx + 2, bnd, cands, hour, minute, timestamp, diff, buf, ans);
            } else {
                runBacktracking(
                    idx + 1, bnd, cands, hour, minute, timestamp, diff, buf, ans);
            }
        }
    }
};


class Solution {
public:
    /**
     * @param time: the given time
     * @return: the next closest time
     */
    string nextClosestTime(string &time) {
        // write your code here

        std::vector<int> pool;
        pool.push_back(time[0] - '0');
        pool.push_back(time[1] - '0');
        pool.push_back(time[3] - '0');
        pool.push_back(time[4] - '0');

        int timestamp =
            (pool[0] * 10 + pool[1]) * 60 + (pool[2] * 10 + pool[3]);

        std::vector<int> config;
        std::vector<int> opt(pool);
        int diff = INT_MAX;

        runBackTracking(pool, 0, 4, timestamp, diff, config, opt);

        std::stringstream stream;
        stream << opt[0] << opt[1] << ':' << opt[2] << opt[3];
        return stream.str();
    }

private:
    void runBackTracking(
            std::vector<int>& pool,
            int depth, int bound,
            int timestamp,
            int& diff,
            std::vector<int>& config,
            std::vector<int>& opt) {

        if (depth == bound) {
            int hour = config[0] * 10 + config[1];
            if (hour > 23) {
                return;
            }

            int minute = config[2] * 10 + config[3];
            if (minute > 59) {
                return;
            }

            int new_timestamp = hour * 60 + minute;
            if (new_timestamp > 1440) {
                return;
            }

            if (new_timestamp == timestamp) {
                return;
            }

            int new_diff;
            if (new_timestamp > timestamp) {
                new_diff = new_timestamp - timestamp;
            } else {
                new_diff = (1440 - timestamp) + new_timestamp;
            }

            if (new_diff < diff) {
                diff = new_diff;
                opt = config;
            }

            return;
        }

        for (int i = 0 ; i < bound ; ++i) {
            config.push_back(pool[i]);
            runBackTracking(
                pool, depth + 1, bound, timestamp, diff, config, opt);
            config.pop_back();
        }
    }
};
