class Solution {
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        // write your code here

        int size = colors.size();
        if (size < 2) {
            return;
        }

        int count[k + 1] = {0};

        for (int color : colors) {
            ++count[color];
        }

        int i = 0;
        int color = 1;
        for (int j = 1 ; j <= k ; ++j) {
            for (int k = 0 ; k < count[j] ; ++k) {
                colors[i++] = color;
            }
            ++color;
        }
    }
};