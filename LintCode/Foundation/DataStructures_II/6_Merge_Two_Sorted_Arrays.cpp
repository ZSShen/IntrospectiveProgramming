class Solution {
public:
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here

        std::vector<int> ans;
        int index_a = 0, size_a = A.size();
        int index_b = 0, size_b = B.size();

        while (index_a < size_a && index_b < size_b) {
            if (A[index_a] < B[index_b]) {
                ans.push_back(A[index_a]);
                ++index_a;
            } else {
                ans.push_back(B[index_b]);
                ++index_b;
            }
        }

        while (index_a < size_a) {
            ans.push_back(A[index_a]);
            ++index_a;
        }

        while (index_b < size_b) {
            ans.push_back(B[index_b]);
            ++index_b;
        }

        return ans;
    }
};