class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) {
            return 0;
        }

        radixSort(nums, size);

        int maxGap = nums[1] - nums[0];
        for (int i = 2 ; i < size ; ++i) {
            int gap = nums[i] - nums[i - 1];
            if (gap > maxGap) {
                maxGap = gap;
            }
        }

        return maxGap;
    }

private:
    void radixSort(std::vector<int>& nums, int size) {
        int maxNum = findMax(nums);

        for (int exp = 1 ; maxNum / exp > 0 ; exp *= 10) {
            countingSort(nums, size, exp);
        }
    }

    int findMax(std::vector<int>& nums) {
        int max = 0;
        for (int num : nums) {
            if (num > max) {
                max = num;
            }
        }
        return max;
    }

    void countingSort(std::vector<int>& nums, int size, int exp) {
        int count[10] = {0};

        for (int num : nums) {
            ++count[(num / exp) % 10];
        }

        for (int i = 1 ; i < 10 ; ++i) {
            count[i] += count[i - 1];
        }

        std::vector<int> sorted(size);
        for (int i = size - 1 ; i >= 0 ; --i) {
            int num = nums[i];
            int digit = (num / exp) % 10;
            sorted[count[digit] - 1] = num;
            --count[digit];
        }

        nums = std::move(sorted);
    }
};
