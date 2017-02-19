class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int sz = height.size();
        if (sz <= 1)
            return 0;

        int l = 0, r = sz - 1;
        int max = 0;
        while (l < r) {
            int area = std::min(height[l], height[r]) * (r - l);
            if (area > max) {
                max = area;
            }

            if (height[l] > height[r]) {
                --r;
            } else if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
                ++l;
            }
        }

        return max;
    }
};