class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int size = nums.size();
        if (size == 0 || size == 1)
            return size;

        // lis : Denote the local maximal length of the increasing sequence.
        //    dp[i]   : Denote the optimal tail element for the length i
        // 1 <= i <= i  increasing sequence.
        int dp[size + 1];
        dp[1] = nums[0];
        int lis = 1;

        // The objective is simple:
        // If we can extend the local maximal length via appending the given element
        // to dp[lis], just do it.
        // Otherwise, we try to optimze the increasing sequence for each length via
        // minimizing the corresponding tail element.
        for (int i = 1 ; i < size ; ++i) {
            int num = nums[i];
            if (num > dp[lis])
                dp[++lis] = num;
            else {
                int bgn = 1, end = lis, mid;
                while (bgn < end) {
                    mid = (bgn + end) >> 1;
                    if (num > dp[mid])
                        bgn = mid + 1;
                    else
                        end = mid;
                }
                dp[bgn] = num;
            }
        }

        return lis;
    }
};
