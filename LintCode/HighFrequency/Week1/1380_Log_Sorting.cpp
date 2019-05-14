

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