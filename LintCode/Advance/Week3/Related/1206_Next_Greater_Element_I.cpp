class Solution {
public:
    /**
     * @param nums1: an array
     * @param nums2: an array
     * @return:  find all the next greater numbers for nums1's elements in the corresponding places of nums2
     */
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        // Write your code here

        /**
         *      1, 3, 4, 2
         *
         *  1: 3         Stack:
         *  3: 4
         *  4: -1           3       4       2
         *  2: -2       1 | 1 | 3 | 3 | 4 | 4
         */

        std::unordered_map<int, int> map;
        std::stack<int> stk;

        for (int num : nums2) {

            map[num] = -1;

            if (stk.empty()) {
                stk.push(num);
                continue;
            }

            while (!stk.empty() && num > stk.top()) {
                map[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }

        std::vector<int> ans;
        for (int num : nums1) {
            ans.push_back(map[num]);
        }

        return ans;
    }
};