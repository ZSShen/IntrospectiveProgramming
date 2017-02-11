class Solution {
public:
    int findMin(vector<int>& nums) {
        int bgn = 0;
        int end = nums.size() - 1;
        while (bgn < end) {
            int mid = (bgn + end) >> 1;
            if (nums[mid] > nums[end]) {
                bgn = mid + 1;
            } else if (nums[mid] < nums[end]) {
                end = mid;
            } else {
                --end;
            }
        }

        return nums[bgn];
    }
};