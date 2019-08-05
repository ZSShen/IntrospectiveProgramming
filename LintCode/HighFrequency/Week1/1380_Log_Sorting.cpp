

struct Record {
    int index;
    std::string id;
    std::string content;

    Record(int index, std::string&& id, std::string&& content)
      : index(index),
        id(id),
        content(content)
    { }
};


struct RecordCompare {

    bool operator() (const Record& lhs, const Record& rhs) {
        int res = lhs.content.compare(rhs.content);
        if (res == 0) {
            return lhs.id < rhs.id;
        }

        return res < 0;
    }
};


class Solution {
public:
    /**
     * @param logs: the logs
     * @return: the log after sorting
     */
    vector<string> logSort(vector<string> &logs) {
        // Write your code here

        /**
         *  A: a line of log that is composed of alphabets.
         *  N: a line of log that is composed of numbers.
         *
         *  A1      A1 (by lexical order)
         *  N1      A2
         *  A2  =>  A3
         *  N2      N1 (by input sequence)
         *  N3      N2
         *  A3      N3
         *
         */

        int size = logs.size();

        std::vector<std::string> ans(size);
        std::vector<Record> letters;

        int offset = size - 1;

        for (int i = size - 1 ; i >= 0 ; --i) {

            const auto& line = logs[i];
            int pos = line.find(' ');
            auto id = line.substr(0, pos);
            auto content = line.substr(pos + 1, line.length() - pos);

            // Check for pure numeric contents.
            bool is_num = true;
            for (char ch : content) {
                if (ch == ' ') {
                    continue;
                }
                if (!('0' <= ch && ch <= '9')) {
                    is_num = false;
                    break;
                }
            }

            if (is_num) {
                ans[offset] = line;
                --offset;
            } else {
                letters.push_back(Record(i, std::move(id), std::move(content)));
            }
        }

        std::sort(letters.begin(), letters.end(), RecordCompare());

        size = letters.size();
        for (int i = 0 ; i < size ; ++i) {
            ans[i] = logs[letters[i].index];
        }

        return ans;
    }
};


struct Record {
    bool is_num;
    int serial;
    std::string id;
    std::string content;

    Record(bool is_num, int serial,
        const std::string& id, const std::string& content)
      : is_num(is_num), serial(serial), id(id), content(content)
    { }
};


class Solution {
public:
    /**
     * @param logs: the logs
     * @return: the log after sorting
     */
    vector<string> logSort(vector<string> &logs) {
        // Write your code here

        int n = logs.size();
        std::vector<Record> records;

        for (int i = 0 ; i < n ; ++i) {
            const auto& line = logs[i];

            auto pos = line.find(' ');
            auto id = line.substr(0, pos);
            ++pos;
            auto content = line.substr(pos, line.length() - pos);
            bool is_num = ('0' <= content[0] && content[0] <= '9');

            records.push_back(Record(is_num, i, id, content));
        }

        std::sort(records.begin(), records.end(),
            [](const auto& lhs, const auto& rhs) {

                // For rule #1.
                if (lhs.is_num != rhs.is_num) {
                    return !lhs.is_num;
                }

                // For rule #3.
                if (lhs.is_num == rhs.is_num && lhs.is_num == true) {
                    return lhs.serial < rhs.serial;
                }

                // For rule #2.
                int order = lhs.content.compare(rhs.content);
                if (order == 0) {
                    return lhs.id < rhs.id;
                }
                return order < 0;
            }
        );

        std::vector<std::string> ans;

        for (const auto& rec : records) {
            ans.push_back(rec.id + " " + rec.content);
        }

        return ans;
    }
};
