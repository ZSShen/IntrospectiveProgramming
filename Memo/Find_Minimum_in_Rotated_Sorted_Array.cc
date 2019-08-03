class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int size = nums.size();
        int prev = nums[0];
        for (int i = 1 ; i < size ; ++i) {
            if (nums[i] > prev)
                prev = nums[i];
            else
                return nums[i];
        }
        return nums[0];
    }
};