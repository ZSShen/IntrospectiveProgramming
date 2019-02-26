class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) {
        // write your code here

        int size = nums.size();
        if (size == 0) {
            return 0;
        }

        int i = 0, j = 0;
        while (j < size) {
            if (nums[j] < k) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                ++i;
            }
            ++j;
        }

        return i;
    }
};