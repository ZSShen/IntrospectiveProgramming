class Solution {
public:
    int search(vector<int>& nums, int target) {

        /**
         * example: 1 2 3 4 5
         *
         * .            *   *
         * case 1:  5 1 2 3 4   2 < 4, the right hand side is sorted.
         *
         *          *   *
         * case 2:  2 3 4 5 1   2 < 4, the left hand side is sorted.
         */

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) >> 1;
            if (target == nums[mid]) {
                return mid;
            }

            // case 1
            if (nums[mid] < nums[right]) {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
                continue;
            }

            // case 2
            if (nums[mid] > nums[right]) {
                if (target < nums[mid] && target >= nums[left]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
                continue;
            }

            // only 1 element remained.
            return -1;
        }

        return -1;
    }
};