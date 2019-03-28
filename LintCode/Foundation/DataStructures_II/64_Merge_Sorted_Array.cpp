class Solution {
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here

        int pivot = m + n - 1;
        int index_a = m - 1;
        int index_b = n - 1;

        while (index_a >= 0 && index_b >= 0) {
            if (A[index_a] > B[index_b]) {
                A[pivot--] = A[index_a--];
            } else {
                A[pivot--] = B[index_b--];
            }
        }

        while (index_a >= 0) {
            A[pivot--] = A[index_a--];
        }
        while (index_b >= 0) {
            A[pivot--] = B[index_b--];
        }
    }
};