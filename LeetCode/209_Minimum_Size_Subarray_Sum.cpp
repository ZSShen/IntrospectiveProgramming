class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        int size = nums.size();
        if (size == 0) {
            return 0;
        }

        int sum = 0;
        int l = 0, r = 0;
        int ans = std::numeric_limits<int>::max();

        while (r < size) {
            sum += nums[r];

            if (sum >= s) {
                do {
                    int window = r - l + 1;
                    ans = std::min(ans, window);

                    sum -= nums[l];
                    ++l;
                } while (sum >= s);
            }

            ++r;
        }

        return (ans != std::numeric_limits<int>::max()) ? ans : 0;
    }
};