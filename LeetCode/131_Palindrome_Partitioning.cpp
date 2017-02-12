class Solution {
public:
    vector<vector<string>> partition(string s) {
        std::vector<std::vector<std::string>> ans;
        int length = s.length();
        if (length == 0) {
            return ans;
        }

        // Construct the palindrome lookup table.
        std::vector<std::vector<bool>> isPalin(length, std::vector<bool>(length));

        for (int i = 0 ; i < length ; ++i) {
            isPalin[i][i] = true;
        }
        for (int i = 0, j = 1 ; i < length - 1 ; ++i, ++j) {
            isPalin[i][j] = s[i] == s[j];
        }
        for (int l = 2 ; l < length ; ++l) {
            for (int i = 0 ; i < length - l ; ++i) {
                int j = i + l;
                isPalin[i][j] = (s[i] == s[j]) && isPalin[i + 1][j - 1];
            }
        }

        // Apply backtracking to discover all the palindrome partitions.
        std::vector<std::vector<std::pair<int, int>>> records;
        std::vector<std::pair<int, int>> partition;
        backtrack(0, length, isPalin, partition, records);

        for (const auto& partition : records) {
            std::vector<std::string> palin;
            for (const auto& pair : partition) {
                int bgn = pair.first;
                int length = pair.second - bgn + 1;
                palin.push_back(s.substr(bgn, length));
            }
            ans.push_back(std::move(palin));
        }

        return ans;
    }

private:
    void backtrack(int bgn, int bound, const std::vector<std::vector<bool>>& isPalin, 
            std::vector<std::pair<int, int>>& partition, 
            std::vector<std::vector<std::pair<int, int>>>& records) {

        if (bgn == bound) {
            records.push_back(partition);
            return;
        }

        for (int end = bgn ; end < bound ; ++end) {
            if (!isPalin[bgn][end]) {
                continue;
            }

            partition.push_back(std::make_pair(bgn, end));
            backtrack(end + 1, bound, isPalin, partition, records);
            partition.pop_back();
        }
    }
};