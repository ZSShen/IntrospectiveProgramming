class Solution {
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
        
        int size = nums.size();
        int k = size - n;
        return quickSelect(nums, 0, size - 1, k);
    }
    
private:
    int quickSelect(std::vector<int>& nums, int bgn, int end, int k) {
        
        int mid = (bgn + end) >> 1;
        int pivot = nums[mid];
        std::swap(nums[mid], nums[end]);
        
        int l = bgn;
        int m = bgn;
        while (l < end) {
            if (nums[l] < pivot) {
                std::swap(nums[m], nums[l]);
                ++m;
            }
            ++l;
        }

        std::swap(nums[m], nums[end]);

        if (k == m) {
            return nums[m];
        }
    
        if (k < m) {
            return quickSelect(nums, bgn, m - 1, k);
        } else {
            return quickSelect(nums, m + 1, end, k);
        }
    }
};