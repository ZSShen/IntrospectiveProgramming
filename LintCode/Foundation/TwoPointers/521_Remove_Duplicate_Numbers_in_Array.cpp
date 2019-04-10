class Solution {
public:
    /**
     * @param nums: an array of integers
     * @return: the number of unique integers
     */
    int deduplication(vector<int> &nums) {
        // write your code here

        int size = nums.size();
        if (size == 0) {
            return 0;
        }

        std::unordered_set<int> set;
        int bgn = -1, end = 0;
        while (end < size) {
            auto& num = nums[end++];
            if (set.count(num) == 0) {
                set.insert(num);
                nums[++bgn] = num;
            }
        }

        return set.size();
    }
};