class Solution {
public:
    /**
     * @param matrix: a boolean 2D matrix
     * @return: an integer
     */
    int maximalRectangle(vector<vector<bool>> &matrix) {
        // write your code here

        /**
         *  1, 1, 0, 0, 1
         *  0, 2, 0, 0, 2
         *  0, 0, 1, 1, 3
         *  0, 0, 2, 2, 4
         *  0, 0, 0, 0, 5
         */

        int num_r = matrix.size();
        if (num_r == 0) {
            return 0;
        }

        int num_c = matrix[0].size();
        if (num_c == 0) {
            return 0;
        }

        int ans = 0;

        std::vector<int> heights(num_c, 0);
        for (int i = 0 ; i < num_r ; ++i) {

            // Build the histogram.
            for (int j = 0 ; j < num_c ; ++j) {
                if (matrix[i][j] == 0) {
                    heights[j] = 0;
                } else {
                    ++heights[j];
                }
            }

            ans = std::max(ans, findMaximalRectangle(heights));
        }

        return ans;
    }

private:
    int findMaximalRectangle(const std::vector<int>& heights) {

        /**
         *   2 1 5 6 2 3
         *
         *         *
         *       * *
         *       * *
         *       * *   *
         *   *   * * * *
         *   * * * * * *
         *
         *  stack: 1
         *         1
         *
         *  h = 5
         *  r = i - 1 = 3
         *  l = (stack.empty()) ? 0 : stack.top() + 1 = 2
         *  area = h * (r - l + 1)
         */

        int n = heights.size();

        int ans = 0;
        std::stack<int> stack;

        for (int i = 0 ; i <= n ; ++i) {

            int curr = (i < n) ? heights[i] : -1;

            while (!stack.empty() && curr <= heights[stack.top()]) {
                int h = heights[stack.top()];
                stack.pop();
                int r = i - 1;
                int l = stack.empty() ? 0 : stack.top() + 1;

                ans = std::max(ans, h * (r - l + 1));
            }

            stack.push(i);
        }

        return ans;
    }
};