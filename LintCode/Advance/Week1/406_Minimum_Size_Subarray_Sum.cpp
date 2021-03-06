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

        int n = nums.size();
        int l = 0;
        int min = INT_MAX;
        int sum = 0;

        for (int r = 0 ; r < n ; ++r) {
            sum += nums[r];

            while (sum >= s && l <= r) {
                int size = r - l + 1;
                min = std::min(min, size);

                sum -= nums[l];
                ++l;
            }
        }

        return (min != INT_MAX) ? min : -1;
    }
};