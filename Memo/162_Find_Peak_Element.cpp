class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        if (nums.size() == 0)
            return -1;
        if (nums.size() == 1)
            return 0;

        int count = nums.size();
        int prev = nums.at(0);
        for (int i = 1 ; i < count ; ++i) {
            int curr = nums.at(i);
            if (curr < prev)
                return i - 1;
            prev = curr;
        }
        return count - 1;
    }
};