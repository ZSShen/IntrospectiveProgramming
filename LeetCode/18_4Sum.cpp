class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        std::vector<std::vector<int>> ans;

        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        int first = 0;

        while (first < size - 3) {

            int second = first + 1;
            while (second < size - 2) {

                int left = second + 1;
                int right = size - 1;
                while (left < right) {
                    int sum = nums[first] + nums[second] + nums[left] + nums[right];
                    if (sum == target) {
                        ans.push_back(
                            std::vector<int> {
                                nums[first],
                                nums[second],
                                nums[left],
                                nums[right]
                            }
                        );

                        ++left;
                        while (left < right && nums[left] == nums[left - 1]) {
                            ++left;
                        }
                        --right;
                        while (left < right && nums[right] == nums[right + 1]) {
                            --right;
                        }
                        continue;
                    }

                    if (sum > target) {
                        --right;
                        while (left < right && nums[right] == nums[right + 1]) {
                            --right;
                        }
                    } else {
                        ++left;
                        while (left < right && nums[left] == nums[left - 1]) {
                            ++left;
                        }
                    }
                }

                ++second;
                while (second < size - 2 && nums[second] == nums[second - 1]) {
                    ++second;
                }
            }

            ++first;
            while (first < size - 3 && nums[first] == nums[first - 1]) {
                ++first;
            }
        }

        return ans;
    }
};