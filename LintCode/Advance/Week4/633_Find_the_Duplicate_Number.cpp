class Solution {
public:
    /**
     * @param nums: an array containing n + 1 integers which is between 1 and n
     * @return: the duplicate one
     */
    int findDuplicate(vector<int> &nums) {
        // write your code here

        int l = 1, r = nums.size() - 1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (countFrequency(nums, m) <= m) {
                l = m;
            } else {
                r = m;
            }
        }

        return (countFrequency(nums, l) <= l) ? r : l;
    }

private:
    int countFrequency(const std::vector<int>& nums, int k) {

        int sum = 0;
        for (int num : nums) {
            if (num <= k) {
                ++sum;
            }
        }
        return sum;
    }

};