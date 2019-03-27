/**
 * Definition of ArrayReader:
 *
 * class ArrayReader {
 * public:
 *     int get(int index) {
 *          // return the number on given index,
 *          // return 2147483647 if the index is invalid.
 *     }
 * };
 */
class Solution {
public:
    /*
     * @param reader: An instance of ArrayReader.
     * @param target: An integer
     * @return: An integer which is the first index of target.
     */
    int searchBigSortedArray(ArrayReader * reader, int target) {
        // write your code here

        int bgn = 0;
        int end = INT_MAX;

        while (bgn + 1 < end) {
            int mid = bgn + (end - bgn) / 2;

            // Check for stream boundary.
            int num = reader->get(mid);
            if (num == INT_MAX) {
                end = mid;
                continue;
            }

            if (target <= num) {
                end = mid;
            } else {
                bgn = mid;
            }
        }

        if (reader->get(bgn) == target) {
            return bgn;
        }
        if (reader->get(end) == target) {
            return end;
        }
        return -1;
    }
};