class Solution {
public:
    /**
     * @param k: An integer
     * @param nums: An integer array
     * @return: kth smallest element
     */
    int kthSmallest(int k, vector<int> &nums) {
        // write your code here
        
        return quickSelect(nums, 0, nums.size() - 1, k - 1);
    }
    
private:
    int quickSelect(std::vector<int>& nums, int bgn, int end, int k) {
        
        int index = (bgn + end) >> 1;
        int pivot = nums[index];
        std::swap(nums[index], nums[end]);

        int l = bgn;
        int m = bgn;
        while (l < end) {
            if (nums[l] < pivot) {
                std::swap(nums[l], nums[m]);
                ++m;
            }
            ++l;
        }
        std::swap(nums[m], nums[end]);
    
        if (m == k) {
            return nums[m];
        }    
        
        if (k < m) {
            return quickSelect(nums, bgn, m - 1, k);
        } else {
            return quickSelect(nums, m + 1, end, k);
        }
    }
};