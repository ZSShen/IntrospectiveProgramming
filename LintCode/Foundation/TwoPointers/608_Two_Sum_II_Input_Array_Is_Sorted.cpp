class Solution {
public:
    /**
     * @param nums: an array of Integer
     * @param target: target = nums[index1] + nums[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here

        std::vector<int> ans;

        int size = nums.size();
        if (size < 2) {
            return ans;
        }

        int l = 0, r = size - 1;
        while (l < r) {
            int sum = nums[l] + nums[r];
            if (sum == target) {
                ans.push_back(l + 1);
                ans.push_back(r + 1);
                break;
            }

            if (sum > target) {
                --r;
                while (l < r && nums[r] == nums[r + 1]) {
                    --r;
                }
            } else {
                ++l;
                while (l < r && nums[l] == nums[l - 1]) {
                    ++l;
                }
            }
        }

        return ans;
    }
};