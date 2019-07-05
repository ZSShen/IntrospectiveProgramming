class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        // write your code here

        /**
         *  preix(i) = num[0] + num[1] + ... + nums[i]
         *  sum(i, j) = prefix(j) - prefix(i - 1)
         *             = nums[i] + num[i + 1] + ... + num[j]
         *
         *  sum(i, j) = 0
         *  => prefix(j) - prefix(i - 1) = 0
         *  => prefix(j) = prefix(i - 1)
         */

        int size = nums.size();

        int sum = 0;
        std::unordered_map<int, int> map;
        map[0] = -1;

        for (int i = 0 ; i < size ; ++i) {
            sum += nums[i];

            if (map.count(sum) == 1) {
                return {map[sum] + 1, i};
            }

            map[sum] = i;
        }

        return {-1, -1};
    }
};