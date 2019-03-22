class Solution {
public:
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
        // write your code here

        return runMergeSort(arrays, 0, arrays.size() - 1);
    }


private:
    std::vector<int> runMergeSort(
            const std::vector<std::vector<int>>& arrays,
            int bgn,
            int end) {

        if (bgn == end) {
            return arrays[bgn];
        }

        int mid = (bgn + end) >> 1;
        auto left = runMergeSort(arrays, bgn, mid);
        auto right = runMergeSort(arrays, mid + 1, end);
        return mergeTwoArrays(left, right);
    }

    std::vector<int> mergeTwoArrays(
            const std::vector<int> src,
            const std::vector<int> dst) {

        std::vector<int> merge;

        int idx_src = 0, size_src = src.size();
        int idx_dst = 0, size_dst = dst.size();

        while (idx_src < size_src && idx_dst < size_dst) {
            if (src[idx_src] < dst[idx_dst]) {
                merge.push_back(src[idx_src]);
                ++idx_src;
            } else {
                merge.push_back(dst[idx_dst]);
                ++idx_dst;
            }
        }

        while (idx_src < size_src) {
            merge.push_back(src[idx_src]);
            ++idx_src;
        }

        while (idx_dst < size_dst) {
            merge.push_back(dst[idx_dst]);
            ++idx_dst;
        }

        return merge;
    }
};