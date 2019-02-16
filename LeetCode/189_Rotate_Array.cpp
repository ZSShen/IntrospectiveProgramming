class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;
        reverse(nums, 0, size - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, size - 1);
    }

private:
    void reverse(std::vector<int>& nums, int bgn, int end) {
        while (bgn < end) {
            std::swap(nums[bgn], nums[end]);
            ++bgn;
            --end;
        }
    }
};