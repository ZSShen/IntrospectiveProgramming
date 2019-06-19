struct Record {
    int x;
    int h;
    char pos;

    Record(int x, int h, char pos)
      : x(x), h(h), pos(pos)
    { }
};


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        std::vector<Record> records;
        for (const auto& building : buildings) {
            int bgn = building[0];
            int end = building[1];
            int h = building[2];

            records.push_back(Record(bgn, h, Pos::BGN));
            records.push_back(Record(end, h, Pos::END));
        }

        std::sort(records.begin(), records.end(),
            [] (const auto& lhs, const auto& rhs) {
                if (lhs.x == rhs.x) {
                    if (lhs.pos == Pos::BGN && lhs.pos == rhs.pos) {
                        return lhs.h > rhs.h;
                    }

                    if (lhs.pos == Pos::END && lhs.pos == rhs.pos) {
                        return lhs.h < rhs.h;
                    }

                    return lhs.pos < rhs.pos;
                }

                return lhs.x < rhs.x;
            }
        );

        std::vector<std::vector<int>> ans;

        std::map<int, int> queue;
        queue[0] = 1;

        int max_height = 0;

        for (const auto& record : records) {
            int x = record.x;
            int h = record.h;

            if (record.pos == Pos::BGN) {
                ++queue[h];
            } else {
                --queue[h];
                if (queue[h] == 0) {
                    queue.erase(h);
                }
            }

            int curr_height = queue.rbegin()->first;
            if (curr_height != max_height) {
                ans.push_back({x, curr_height});
                max_height = curr_height;
            }
        }

        return ans;
    }

private:
    enum Pos {
        BGN,
        END
    };

};
