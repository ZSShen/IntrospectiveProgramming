class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        // write your code here

        /**
         *          *
         *        * *
         *        * *
         *        * *   *
         *    *   * * * *
         *    * * * * * *
         *    2 1 5 6 2 3
         *
         */

        int size = height.size();
        if (size == 0) {
            return 0;
        }

        std::stack<int> stack;
        int ans = 0;

        for (int i = 0 ; i <= size ; ++i) {
            int curr = (i < size) ? height[i] : -1;

            while (!stack.empty() && curr <= height[stack.top()]) {
                int h = height[stack.top()];
                stack.pop();
                int l = stack.empty() ? 0 : stack.top() + 1;
                int r = i - 1;

                ans = std::max(ans, (r - l + 1) * h);
            }

            stack.push(i);
        }

        return ans;
    }
};