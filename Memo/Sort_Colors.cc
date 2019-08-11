class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        // Simplified counting sort.

        int count[3];

        count[0] = count[1] = count[2] = 0;
        for (int num : nums)
            ++count[num];

        int bgn = 0, end = count[0];
        for (int i = bgn ; i < end ; ++i)
            nums[i] = 0;
        bgn = end, end += count[1];
        for (int i = bgn ; i < end ; ++i)
            nums[i] = 1;
        bgn = end, end += count[2];
        for (int i = bgn ; i < end ; ++i)
            nums[i] = 2;

        return;
    }
};
