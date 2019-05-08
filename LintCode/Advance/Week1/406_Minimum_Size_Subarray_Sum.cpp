class Solution {
public:
    /**
     * @param nums: an array of integers
     * @param s: An integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here

        /**
         *    l
         *          r
         *  a b c d e f g h i
         *
         */

        int size = nums.size();
        if (size == 0) {
            return -1;
        }

        int l = 0, r = 0;
        int sum = 0;
        int ans = std::numeric_limits<int>::max();

        while (r < size) {
            sum += nums[r];

            if (sum >= s) {
                do {
                    int window = r - l + 1;
                    ans = std::min(ans, window);
                    sum -= nums[l];
                    ++l;
                } while (sum >= s);
            }
            ++r;
        }

        return (ans != std::numeric_limits<int>::max())? ans : -1;
    }
};