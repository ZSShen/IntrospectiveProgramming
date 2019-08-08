class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &numbers) {
        // write your code here

        std::vector<std::vector<int>> ans;
        int size = numbers.size();
        if (size < 3) {
            return ans;
        }

        std::sort(numbers.begin(), numbers.end());

        int s = 0;
        while (s < size) {
            if (numbers[s] > 0) {
                break;
            }

            int l = s + 1, r = size - 1;
            int target = 0 - numbers[s];

            while (l < r) {
                int sum = numbers[l] + numbers[r];

                if (sum == target) {
                    std::vector<int> triplets = {
                        numbers[s],
                        numbers[l],
                        numbers[r]
                    };
                    ans.push_back(std::move(triplets));

                    while (l < --r && numbers[r] == numbers[r + 1]);
                    while (++l < r && numbers[l] == numbers[l - 1]);
                } else {
                    if (sum > target) {
                        while (l < --r && numbers[r] == numbers[r + 1]);
                    } else {
                        while (++l < r && numbers[l] == numbers[l - 1]);
                    }
                }
            }

            while (++s < size && numbers[s] == numbers[s - 1]);
        }

        return ans;
    }
};


class Solution {
public:
    /**
     * @param nums: Give an array nums of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &nums) {
        // write your code here

        int n = nums.size();
        if (n == 0) {
            return {};
        }

        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> ans;
        for (int i = 0 ; i < n - 2 ; ++i) {
            // Dedup.
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Since the remaining numbers are all positive, it is impossible
            // to generate the legal triplets. Thus, we break the loop here
            // to avoid redundant computions.
            if (nums[i] > 0) {
                break;
            }

            twoSum(nums, i + 1, n - 1, -nums[i], ans);
        }

        return ans;
    }

private:
    void twoSum(const auto& nums, int bgn, int end, int target, auto& ans) {

        int l = bgn, r = end;
        while (l < r) {
            int sum = nums[l] + nums[r];

            if (sum == target) {
                ans.push_back({-target, nums[l], nums[r]});

                // Dedup.
                while (++l < r && nums[l] == nums[l - 1]);
                while (l < --r && nums[r] == nums[r + 1]);

                continue;
            }

            // Narrow the window and dedup.
            if (sum < target) {
                while (++l < r && nums[l] == nums[l - 1]);
            } else {
                while (l < --r && nums[r] == nums[r + 1]);
            }
        }
    }
};