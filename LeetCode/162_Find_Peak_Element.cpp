class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int size = nums.size();
        if (size == 1) { // Please be careful about the edge case [-2147483648]
            return 0;
        }

        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (mid == size - 1) {
                if (nums[mid] > nums[mid - 1]) {
                    return mid;
                }
                right = mid - 1;
                continue;
            }

            if (mid == 0) {
                if (nums[mid] > nums[mid + 1]) {
                    return mid;
                }
                left = mid + 1;
                continue;
            }

            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                return mid;
            }

            if (nums[mid - 1] > nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};