class Solution {
public:
    int trap(vector<int>& height) {

        int size = height.size();
        std::vector<std::vector<int>> dp(2, std::vector<int>(size, 0));

        int max_left = 0, max_right = 0;
        for (int i = 0, j = size - 1 ; i < size ; ++i, --j) {
            dp[Direct::L][i] = max_left = std::max(height[i], max_left);
            dp[Direct::R][j] = max_right = std::max(height[j], max_right);
        }

        int sum = 0;
        for (int i = 0 ; i < size ; ++i) {
            sum += std::min(dp[Direct::L][i], dp[Direct::R][i]) - height[i];
        }

        return sum;
    }

private:
    enum Direct {
        L,
        R
    };
};