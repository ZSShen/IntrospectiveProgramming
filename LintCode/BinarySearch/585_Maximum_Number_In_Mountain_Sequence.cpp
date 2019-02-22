class Solution {
public:
    /**
     * @param nums: a mountain sequence which increase firstly and then decrease
     * @return: then mountain top
     */
    int mountainSequence(vector<int> &nums) {
        // write your code here

        int size = nums.size();
        int l = 0, r = size - 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[m + 1]) {
                l = m;
            } else {
                r = m;
            }
        }

        return std::max(nums[l], nums[r]);
    }
};