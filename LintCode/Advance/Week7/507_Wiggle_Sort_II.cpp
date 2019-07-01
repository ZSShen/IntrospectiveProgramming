class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        // write your code here

        /**
         *  If i is even, nums[i] < nums[i - 1]
         *  If i is odd,  nums[i] > nums[i - 1]
         *
         *  ex. 1, 1, 1, 4, 6
         *
         *  LLLLLLLMGGGGGG
         *
         */

        int n = nums.size();
        if (n <= 1) {
            return;
        }

        int bgn = 0;
        int end = n - 1;
        int mid = (bgn + end) / 2;

        quickSelect(nums, bgn, end, mid);
        distribute(nums, mid, n);
    }

private:
    // Return the index of the median.
    void quickSelect(std::vector<int>& nums, int bgn, int end, int target) {

        int mid = (bgn + end) / 2;

        int pivot = nums[mid];
        std::swap(nums[mid], nums[end]);

        int j = bgn; // j points to the tail of the consecutive numbers which
                     // are less than or equal to pivot.
        for (int i = bgn ; i < end ; ++i) {
            if (nums[i] <= pivot) {
                std::swap(nums[i], nums[j]);
                ++j;
            }
        }

        std::swap(nums[end], nums[j]);

        if (j == target) {
            return;
        }

        if (j < target) {
            quickSelect(nums, j + 1, end, target);
        } else {
            quickSelect(nums, bgn, j - 1, target);
        }
    }


    void distribute(std::vector<int>& nums, int mid, int n) {

        // L M G G
        // L L M G G

        std::vector<int> ref(nums);

        for (int i = mid, j = 0 ; i >= 0 ; --i, j += 2) {
            nums[j] = ref[i];
        }

        for (int i = n - 1, j = 1 ; i > mid ; --i, j += 2) {
            nums[j] = ref[i];
        }
    }
};