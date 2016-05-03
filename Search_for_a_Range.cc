class Solution {
public:
    Solution()
    {
        sol_[0] = sol_[1] = -1;
    }

    vector<int> searchRange(vector<int>& nums, int target)
    {
        int size = nums.size();

        if (target < nums[0])
            return vector<int>(sol_, sol_ + 2);
        if (target > nums[size - 1])
            return vector<int>(sol_, sol_ + 2);

        // Search for the element equal to the given number.
        int mid;
        int bgn = 0, end = size - 1;
        while (bgn < end) {
            mid = (bgn + end) >> 1;
            if (target == nums[mid])
                break;
            if (target > nums[mid])
                bgn = mid + 1;
            else
                end = mid - 1;
        }

        mid = (bgn + end) >> 1;
        if (nums[mid] != target)
            return vector<int>(sol_, sol_ + 2);

        // Locate the lower bound.
        int lower = mid - 1;
        while (lower >= 0) {
            if (nums[lower] != target)
                break;
            --lower;
        }

        // Locate the upper bound.
        int upper = mid + 1;
        while (upper < size) {
            if (nums[upper] != target)
                break;
            ++upper;
        }

        sol_[0] = lower + 1;
        sol_[1] = upper - 1;
        return vector<int>(sol_, sol_ + 2);
    }

private:
    int sol_[2];
};
