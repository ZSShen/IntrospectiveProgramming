
class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> &nums) {
        // write your code here

        int size = nums.size();
        if (size == 0) {
            return {-1, -1};
        }
        if (size == 1) {
            return {0, 0};
        }

        std::vector<std::pair<int, int>> records;
        records.push_back(std::make_pair(nums[0], 0));

        int sum = nums[0];
        for (int i = 1 ; i < size ; ++i) {
            sum += nums[i];
            records.push_back(std::make_pair(sum, i));
        }

        std::sort(records.begin(), records.end(),
            [] (const std::pair<int, int>& src,
                const std::pair<int, int>& dst) -> bool {
                    return src.first < dst.first;
            });

        int diff = INT_MAX;
        int bgn, end;
        for (int i = 1 ; i < size ; ++i) {
            int temp = std::abs(records[i].first - records[i - 1].first);
            if (temp < diff) {
                bgn = i - 1;
                end = i;
                diff = temp;
            }
        }

        std::vector<int> ans;
        ans.push_back(records[bgn].second);
        ans.push_back(records[end].second);
        std::sort(ans.begin(), ans.end());
        ++ans[0];

        return ans;

        /**
         *   -3, 1, 1, -3, 5
         *
         *   (-3, 0)     (-4, 3)
         *   (-2, 1)     (-3, 0) (1 3)
         *   (-1, 2) =>  (-2, 1)
         *   (-4, 3)     (-1, 2)
         *   ( 1, 4)     ( 1, 4)
         */
    }
};