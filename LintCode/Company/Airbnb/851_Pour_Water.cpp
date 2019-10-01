class Solution {
public:
    /**
     * @param heights: the height of the terrain
     * @param V: the units of water
     * @param K: the index
     * @return: how much water is at each index
     */
    vector<int> pourWater(vector<int> &heights, int V, int K) {
        // Write your code here


        /**
         *         w
         *   # w w # w # #
         *   # # # # # # #
         * [ 2 1 1 2 1 2 2 ]
         *
         *   0 1 2 3 4 5 6
         */

        int n = heights.size();
        if (K >= n) {
            return heights;
        }

        for (int i = 0 ; i < V ; ++i) {

            int h = heights[K];
            bool found = false;

            // Explore the left portion of the terrain.
            int j = K - 1;
            int place = K;
            while (j >= 0 && heights[j] <= heights[j + 1]) {
                if (heights[j] < heights[j + 1] && heights[j] < heights[place]) {
                    place = j;
                }
                --j;
            }

            if (place != K) {
                ++heights[place];
                continue;
            }

            // Explore the right portion of the terrain.
            j = K + 1;
            place = K;
            while (j < n && heights[j] <= heights[j - 1]) {
                if (heights[j] < heights[j - 1] && heights[j] < heights[place]) {
                    place = j;
                }
                ++j;
            }

            if (place != K) {
                ++heights[place];
                continue;
            }

            ++heights[K];
        }

        return heights;
    }
};
