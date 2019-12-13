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

        int r = 1;
        while (reader->get(r) < target) {
            r <<= 1;
        }

        int l = 0;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (target > reader->get(m)) {
                l = m;
            } else {
                r = m;
            }
        }

        if (reader->get(l) == target) {
            return l;
        }
        if (reader->get(r) == target) {
            return r;
        }
        return -1;
    }
};