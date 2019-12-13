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


class Solution {
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        // write your code here

        divideAndConquer(colors, 0, colors.size() - 1, 1, k);
    }

private:
    void divideAndConquer(
        auto& colors, int left, int right, int min, int max) {

        if (min == max) {
            return;
        }
        if (left >= right) {
            return;
        }

        int l = left, r = right;
        int mid = (min + max) / 2;

        while (l <= r) {

            while (l <= r && colors[l] <= mid) {
                ++l;
            }
            while (l <= r && colors[r] > mid) {
                --r;
            }

            if (l <= r) {
                std::swap(colors[l], colors[r]);
                ++l;
                --r;
            }
        }

        divideAndConquer(colors, left, r, min, mid);
        divideAndConquer(colors, l, right, mid + 1, max);
    }
};