class Solution {
public:
    /**
     * @param heights: a list of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here

        /**
         *
         *           *
         *      *   *** *
         *   _*_**_*******
         *
         *  # of units = std::min(right_walls[i], left_walls[i]) - heights[i]
         */

        int size = heights.size();
        if (size == 0) {
            return 0;
        }

        std::vector<int> right_walls(size, 0);
        right_walls[size - 1] = heights[size - 1];
        for (int i = size - 2 ; i >= 0 ; --i) {
            right_walls[i] = std::max(right_walls[i + 1], heights[i]);
        }

        int sum = 0;
        int left_wall = 0;
        for (int i = 0 ; i < size ; ++i) {
            left_wall = std::max(left_wall, heights[i]);

            int bound = std::min(left_wall, right_walls[i]);
            int unit = (bound > heights[i]) ? (bound - heights[i]) : 0;
            sum += unit;
        }

        return sum;
    }
};