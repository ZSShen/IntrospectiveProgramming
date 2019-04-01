class Solution {
public:
    /**
     * @param A: an array
     * @return: total of reverse pairs
     */
    long long reversePairs(vector<int> &A) {
        // write your code here

        int size = A.size();
        if (size == 0) {
            return 0;
        }

        long long count = 0;
        runMergeSort(0, size - 1, A, count);
        return count;
    }

private:
    std::vector<int> runMerge(
        const std::vector<int>& src,
        const std::vector<int>& dst,
        long long& count) {

        int size_src = src.size();
        int size_dst = dst.size();

        std::vector<int> merge;

        int i = 0, j = 0;
        while (i < size_src && j < size_dst) {
            if (dst[j] >= src[i]) {
                merge.push_back(src[i]);
                ++i;
            } else {
                // Count the inversion pairs here.
                count += size_src - i;

                merge.push_back(dst[j]);
                ++j;
            }
        }

        while (i < size_src) {
            merge.push_back(src[i++]);
        }
        while (j < size_dst) {
            merge.push_back(dst[j++]);
        }

        return merge;
    }

    std::vector<int> runMergeSort(
        int l, int r, const std::vector<int>& nums, long long& count) {

        if (l == r) {
            return {nums[l]};
        }

        int m = (l + r) >> 1;
        auto src = runMergeSort(l, m, nums, count);
        auto dst = runMergeSort(m + 1, r, nums, count);
        return runMerge(src, dst, count);
    }
};