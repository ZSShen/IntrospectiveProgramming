class Solution {
public:
    /**
     * @param nums: an array containing n + 1 integers which is between 1 and n
     * @return: the duplicate one
     */
    int findDuplicate(vector<int> &nums) {
        // write your code here

        /**
         *  There are (n + 1) numbers, and suppose that p is the duplicate.
         *  We can divide these numbers into 3 portions.
         *
         *  1, 2, ..., (p - 1) | p, ..., p | (p + 1), ..., n
         *
         *  Based on the pigeon hole theory,
         *
         *  The amount of numbers <= p       :  >= (p + 1) at least
         *  The amount of numbers <= x, x > p:  >= (x + 1) at least
         *  The amount of numbers <= y, y < p:  <= y       at most
         *
         *  Thus, we can use binary approximation to guess a number x and
         *  calculate how many numbers are less than or equal to x. If the
         *  amount of numbers that are <= x is >= (x + 1), we know that we
         *  should decrase the upper bound to find our target. Otherwise,
         *  if the amount of numbers that are <= x is <= x, we should increase
         *  the lower bound.
         *
         *  O(nlogn)
         */

        int l = 1, r = nums.size() - 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;

            if (countNumber(nums, m) >= m + 1) {
                r = m;
            } else {
                l = m;
            }
        }

        return (countNumber(nums, l) <= l) ? r : l;
    }

private:
    int countNumber(const auto& nums, int x) {

        int sum = 0;
        for (int num : nums) {
            if (num <= x) {
                ++sum;
            }
        }

        return sum;
    }
};