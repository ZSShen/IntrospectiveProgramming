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
    int quickSelect(auto& nums, int bgn, int end, int k) {

        int mid = (bgn + end) / 2;
        int pivot = nums[mid];

        std::swap(nums[mid], nums[end]);

        int l = bgn, r = bgn;
        while (r < end) {
            if (nums[r] < pivot) {
                std::swap(nums[l], nums[r]);
                ++l;
            }
            ++r;
        }

        std::swap(nums[end], nums[l]);

        if (l == k) {
            return pivot;
        }

        if (k < l) {
            return quickSelect(nums, bgn, l - 1, k);
        } else {
            return quickSelect(nums, l + 1, end, k);
        }
    }
};