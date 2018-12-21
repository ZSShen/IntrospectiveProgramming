class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        std::vector<std::vector<int>> ans;
        std::sort(nums.begin(), nums.end());

        int i = 0;
        int size = nums.size();
        while (i < size) {
            if (nums[i] > 0) {
                break;
            }

            int j = i + 1;
            int k = size - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    std::vector<int> tuple {
                        nums[i],
                        nums[j],
                        nums[k]
                    };
                    ans.push_back(tuple);

                    ++j;
                    --k;

                    while (j < k && nums[j] == nums[j - 1]) {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        --k;
                    }
                } else if (sum > 0) {
                    --k;
                } else {
                    ++j;
                }
            }

            ++i;
            while (i < size && nums[i] == nums[i - 1]) {
                ++i;
            }
        }

        return ans;
    }
};