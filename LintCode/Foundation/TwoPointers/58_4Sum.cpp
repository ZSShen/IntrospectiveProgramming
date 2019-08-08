class Solution {
public:
    /**
     * @param numbers: Give an array
     * @param target: An integer
     * @return: Find all unique quadruplets in the array which gives the sum of zero
     */
    vector<vector<int>> fourSum(vector<int> &numbers, int target) {
        // write your code here

        std::vector<std::vector<int>> ans;

        int size = numbers.size();
        if (size < 4) {
            return ans;
        }

        std::sort(numbers.begin(), numbers.end());

        if (target <= 0 && numbers[0] > 0) {
            return ans;
        }

        int i = 0;
        while (i < size - 3) {
            int minus_i = target - numbers[i];

            int j = i + 1;
            if (!(minus_i <= 0 && numbers[j] > 0)) {
                while (j < size - 2) {
                    int minus_i_j = minus_i - numbers[j];

                    int l = j + 1, r = size - 1;
                    if (!(minus_i_j <= 0 && numbers[l] > 0)) {
                        runTwoSum(numbers, i, j, l, r, minus_i_j, ans);
                    }

                    while (++j < size - 2 && numbers[j] == numbers[j - 1]);
                }
            }

            while (++i < size - 3 && numbers[i] == numbers[i - 1]);
        }

        return ans;
    }

private:
    inline void runTwoSum(
            std::vector<int>& numbers,
            int i, int j, int l, int r,
            int target,
            std::vector<std::vector<int>>& ans) {

        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) {
                std::vector<int> tuple {
                    numbers[i],
                    numbers[j],
                    numbers[l],
                    numbers[r]
                };
                ans.push_back(std::move(tuple));

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
    }

};


class Solution {
public:
    /**
     * @param numbers: Give an array
     * @param target: An integer
     * @return: Find all unique quadruplets in the array which gives the sum of zero
     */
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        // write your code here

        int n = nums.size();
        if (n == 0) {
            return {};
        }

        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> ans;

        for (int f = 0 ; f < n - 3 ; ++f) {
            if (f > 0 && nums[f] == nums[f - 1]) {
                continue;
            }

            for (int s = f + 1 ; s < n - 2 ; ++s) {
                if (s > f + 1 && nums[s] == nums[s - 1]) {
                    continue;
                }

                twoSum(nums, s + 1, n - 1, nums[f], nums[s], target, ans);
            }
        }

        return ans;
    }

private:
    void twoSum(
            const auto& nums, int bgn, int end,
            int first, int second, int target, auto& ans) {

        int l = bgn, r = end;
        int cache = first + second;

        while (l < r) {
            int sum = nums[l] + nums[r] + cache;
            if (sum == target) {
                ans.push_back({first, second, nums[l], nums[r]});

                while (++l < r && nums[l] == nums[l - 1]);
                while (l < --r && nums[r] == nums[r + 1]);

                continue;
            }

            if (sum > target) {
                while (l < --r && nums[r] == nums[r + 1]);
            } else {
                while (++l < r && nums[l] == nums[l - 1]);
            }
        }
    }
};