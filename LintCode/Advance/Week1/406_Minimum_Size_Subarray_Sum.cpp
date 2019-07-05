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
         *  Use 2 pointers, r and l, to scan the prefix sum array. In the
         *  procedure, r is the main pointer which controls the movement of
         *  our sliding window. Each time, when the subarray sum bounded by
         *  r and l, namely prefix[r] - prefix[l], is less than or eqaul to
         *  s, we try to adjust l so that we are able to get a smaller window
         *  that also fulfills the problem descpretion.
         *
         *  Note: In real implementation, we may use a single varable to
         *        represent the prefix sum array.
         *
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