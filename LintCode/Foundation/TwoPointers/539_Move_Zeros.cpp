class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int> &nums) {
        // write your code here

        int size = nums.size();
        if (size <= 1) {
            return;
        }

        int l = 0, r = 0;
        while (r < size) {
            if (nums[r] != 0) {
                std::swap(nums[l], nums[r]);
                ++l;
            }
            ++r;
        }
    }
};