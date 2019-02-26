class Solution {
public:
    /*
     * @param nums: an array of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here

        int size = nums.size();
        if (size < 2)  {
            return;
        }

        int i = 0, j = 0;
        while (j < size) {
            if (nums[j] >> 1 << 1 != nums[j]) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                ++i;
            }
            ++j;
        }
    }
};