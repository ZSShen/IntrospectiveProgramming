class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &heights) {
        // write your code here

        /**
         *
         *         *
         *       * *
         *       * *
         *       * *   *
         *   *   * * * *
         *   * * * * * *
         *   2 1 5 6 2 3
         *
         *
         *   Let's consider the siutation that the stack has 1, 5, and 6, and
         *   then we see 2, the number that is less than 6.
         *   As a result, we can acquire the following rectangles.
         *
         *   1st:   2nd:
         *
         *    *
         *    *     * *
         *    *     * *
         *    *     * *
         *    *     * *
         *    *     * *
         *    6     5 6
         *
         *    1x6   2x5
         *
         *    Let' consider the situation that the stack has 1, 2, 3, and
         *    then we use a dummy number, -1, to trigger the last examination.
         *    As a result, we can acquire the following rectangles.
         *
         *   1st:   2nd:       3rd:
         *
         *    *
         *    *     * * * *
         *    *     * * * *    * * * * * *
         *    3     5 6 2 3    2 1 5 6 2 3
         *
         *    1x3   4x2        6x1
         *
         */

        int n = heights.size();
        if (n == 0) {
            return 0;
        }

        int max = 0;
        std::stack<int> stk;

        for (int i = 0 ; i <= n ; ++i) {

            int curr = (i < n) ? heights[i] : -1;

            while (!stk.empty() && curr <= heights[stk.top()]) {

                int height = heights[stk.top()];
                stk.pop();

                int l = (!stk.empty()) ? stk.top() + 1 : 0;
                int r = i - 1;

                max = std::max(max, (r - l + 1) * height);
            }

            stk.push(i);
        }

        return max;
    }
};