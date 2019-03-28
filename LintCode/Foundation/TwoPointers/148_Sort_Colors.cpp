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