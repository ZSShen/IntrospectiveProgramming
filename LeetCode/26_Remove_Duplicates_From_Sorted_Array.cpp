class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int size = nums.size();
        if (size <= 1) {
            return size;
        }

        int l = 0, r = 0;
        while (r < size) {
            if (nums[l] != nums[r]) {
                nums[++l] = nums[r];
            }
            ++r;
        }

        return l + 1;
    }
};