class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: nothing
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        
        int size = nums.size();
        int i;
        for (i = size - 2 ; i >= 0 ; --i) {
            if (nums[i] <  nums[i + 1]) {
                break;
            }
        }
        
        // The input is the max permuation. 
        // E.g: abcd.  a > b > c > d
        if (i == -1) {
            swapByRange(nums, 0, size - 1);
            return;
        }
        
        int j;
        for (j = size - 1 ; j >= 0 ; --j) {
            if (nums[j] > nums[i]) {
                break;
            }
        }
        
        std::swap(nums[i], nums[j]);
        swapByRange(nums, i + 1, size - 1);
    }

private:
    void swapByRange(
            std::vector<int>& nums,
            int bgn,
            int end) {
        
        int mid = (bgn + end) / 2;
        for (int i = bgn, j = end ; i <= mid ; ++i, --j) {
            std::swap(nums[i], nums[j]);
        }
    }
};