class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {

        /**
         *  DP Formula:
         *
         *  Let ways[i][j] denotes the number of ways to sum up j using
         *  the first i elements.
         *
         *  ways[i][j] = ways[i - 1][j - num[i]] +  # the sum of the first i - 1 elements is j + num[i]
         *               ways[i - 1][j + nums[i]]   # the sum of the first i - 1 elements is j - num[i]
         */

        int count_num = nums.size();
        if (count_num == 0) {
            return 0;
        }

        std::vector<std::unordered_map<int, int>> ways(
            count_num, std::unordered_map<int, int>());

        ways[0][nums[0]] += 1;
        ways[0][-nums[0]] += 1;

        for (int i = 1 ; i < count_num ; ++i) {
            int num = nums[i];

            for (const auto& pair : ways[i - 1]) {
                int sum = pair.first;
                int way = pair.second;

                ways[i][sum + num] += way;
                ways[i][sum - num] += way;
            }
        }

        return ways[count_num - 1][S];
    }
};