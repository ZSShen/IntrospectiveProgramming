class Solution {
public:
    int minSubArrayLen(int constraint, vector<int>& nums)
    {
        size_t size = nums.size();
        if (size == 0)
            return 0;

        size_t bgn = 0, end = 0, min = size + 1;
        int sum = nums[0];
        while (true) {
            if (sum < constraint) {
                ++end;
                if (end == size)
                    break;
                sum += nums[end];
            } else {
                size_t len = end - bgn + 1;
                if (len < min)
                    min = len;
                if (bgn == end) {
                    ++end;
                    if (end == size)
                        break;
                    sum += nums[end];
                } else {
                    sum -= nums[bgn];
                    ++bgn;
                }
            }
        }

        return (min == size + 1)? 0 : min;
    }
};