class Solution {
public:
    /**
     * @param nums: an array
     * @return: the Next Greater Number for every element
     */
    vector<int> nextGreaterElements(vector<int> &nums) {
        // Write your code here

        /**
         *   4 3 2 5 6 1 2
         *
         *   4: 5           Stack:
         *   3: 5                       5
         *   2: 5                   2   2               2
         *   5: 6               3   3   3   6       1 | 1 | 2
         *   6: no          4 | 4 | 4 | 4 | 5 | 5 | 6 | 6 | 6 | 6
         *   1: 2
         *   2: no
         *
         */

        int n = nums.size();
        if (n == 0) {
            return {};
        }

        std::vector<int> ans(n, -1);
        std::stack<int> stk;

        for (int ii = 0 ; ii < n * 2; ++ii) {
            int i = ii % n;

            if (stk.empty()) {
                stk.push(i);
                continue;
            }

            int curr = nums[i];
            if (curr < nums[stk.top()]) {
                stk.push(i);
                continue;
            }

            while (!stk.empty() && curr > nums[stk.top()]) {
                int index = stk.top();
                stk.pop();
                ans[index] = curr;
            }
            stk.push(i);
        }

        return ans;
    }
};