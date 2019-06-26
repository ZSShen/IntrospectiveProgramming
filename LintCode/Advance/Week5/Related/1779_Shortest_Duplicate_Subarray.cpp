class Solution {
public:
    /**
     * @param arr: The array you should find shortest subarray length which has duplicate elements.
     * @return: Return the shortest subarray length which has duplicate elements.
     */
    int getLength(vector<int> &arr) {
        // Write your code here.

        /**
         *  1, 2, 3, 1, 4, 5, 4, 6, 8
         *
         *  {1, 3} w = 4
         *  {2, 1}
         *  {3, 2}
         *  {4, 6} w = 3
         *  {5, 5}
         *  {6, 7}
         *  {8, 8}
         */

        std::unordered_map<int, int> map;
        int n = arr.size();
        int ans = -1;

        for (int i = 0 ; i < n ; ++i) {
            int num = arr[i];

            if (map.count(num) == 0) {
                map[num] = i;
            } else {
                int window = i - map[num] + 1;
                if (ans == - 1) {
                    ans = window;
                } else {
                    ans = std::min(ans, window);
                }
                map[num] = i;
            }
        }

        return ans;
    }
};