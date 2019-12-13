class Solution {
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2
     * @return: nothing
     */
    void sortColors(vector<int> &nums) {
        // write your code here

        int size = nums.size();
        if (size < 2) {
            return;
        }

        int i = 0, l = 0, r = size - 1;
        while (i <= r) {
            if (nums[i] == 0) {
                std::swap(nums[i], nums[l]);
                ++i;
                ++l;
            } else if (nums[i] == 1) {
                ++i;
            } else {
                std::swap(nums[i], nums[r]);
                --r;
            }
        }
    }
};


class Solution {
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2
     * @return: nothing
     */
    void sortColors(vector<int> &nums) {
        // write your code here

        int n = nums.size();
        int zero = 0, one = 0, two = n - 1;

        /**
         * We use 3 pointers to track the elements:
         *
         *  1. The "one" pointer guides the scanning procedure.
         *  2. The "zero" pointer points to tail of the consecutive zeros, which
         *     are shifted to the left hand side of the array.
         *  3. The "two" pointer points to the head of the consecutive twos,
         *     which are shifted to the right hand side of the array.
         *
         *       zero     two
         *          |     |
         *          v     v
         *  0 0 0 0 1 1 1 1 2 2 2 2
         */

        while (one <= two) {
            if (nums[one] == 0) {
                std::swap(nums[one], nums[zero]);
                ++zero;
                ++one;
            } else if (nums[one] == 2) {
                std::swap(nums[one], nums[two]);
                --two;
            } else {
                ++one;
            }
        }
    }
};