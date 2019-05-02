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