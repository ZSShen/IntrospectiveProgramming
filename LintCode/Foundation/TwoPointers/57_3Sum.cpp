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