class Solution {
public:
    int maxProduct(vector<string>& words) {

        std::vector<Record> records;
        for (const auto& word : words) {
            int charSet = 0;
            int length = 0;
            for (char ch : word) {
                charSet |= 1 << (ch - 'a');
                ++length;
            }
            records.push_back(Record(charSet, length));
        }

        int ans = 0;
        int sz = records.size();
        for (int i = 0 ; i < sz ; ++i) {
            for (int j = 0 ; j < sz ; ++j) {
                if (i == j) {
                    continue;
                }

                if ((records[i].charSet & records[j].charSet) != 0) {
                    continue;
                }         

                int length = records[i].length * records[j].length;
                if (length > ans) {
                    ans = length;
                }
            }
        }

        return ans;
    }

private:
    struct Record {
        int charSet;
        int length;
        Record(int charSet, int length)
            : charSet(charSet), length(length)
        {}
    };
};