class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int size = nums.size();
        if (size < 1) {
            return std::vector<int>{-1, -1};
        }

        int left = 0, right = size - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid;
            } else {
                right = mid;
            }
        }

        int bgn = -1;
        if (nums[left] == target) {
            bgn = left;
        } else if (nums[right] == target) {
            bgn = right;
        }
        if (bgn == -1) {
            return std::vector<int>{-1, -1};
        }

        left = bgn, right = size - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid;
            }
        }

        int end;
        if (nums[right] == target) {
            end = right;
        } else if (nums[left] == target) {
            end = left;
        }

        return std::vector<int>{bgn, end};
    }
};