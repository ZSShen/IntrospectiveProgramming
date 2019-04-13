class Solution {
public:
    /*
     * @param A: An integer array.
     * @return: nothing
     */
    void rerange(vector<int> &A) {
        // write your code here
        
        int size = A.size();
        if (size == 0) {
            return;
        }

        int l = 0;
        int count_positive = 0;
        for (int i = 0 ; i < size ; ++i) {
            if (A[i] > 0) {
                std::swap(A[i], A[l]);
                ++l;
                ++count_positive;
            }
        }
        
        int count_negative = size - count_positive;
        if (count_positive > count_negative) {
            adjust(A, 0, 1);
        } else {
            adjust(A, 1, 0);
        }
    }
    
private:
    void adjust(std::vector<int>& A, int positive_pos, int negative_pos) {

        int size = A.size();

        // Arrange positive numbers.
        int l = negative_pos;
        for (int i = positive_pos ; i < size ; i += 2) {
            if (A[i] < 0) {
                std::swap(A[i], A[l]);
                l += 2;
                while (l < size && A[l] < 0) {
                    l += 2;
                }
                if (l >= size) {
                    break;
                }
            }
        }

        // Set up the pointer to adjust negative numbers.
        int r = size - 1;
        if (r >> 1 << 1 == r) {
            if (negative_pos == 0) {
                --r;
            }
        } else {
            if (negative_pos == 1) {
                --r;
            }
        }
        while (r >= 0 && A[r] > 0) {
            r -= 2;
        }
        if (r < 0) {
            return;
        }
        
        // Arrange negative numbers.
        for (int i = negative_pos ; i < size ; i += 2) {
            if (A[i] > 0) {
                std::swap(A[i], A[r]);
                r -= 2;
                while (r >= 0 && A[r] > 0) {
                    r -= 2;
                }
                if (r < 0) {
                    break;
                }
            }
        }        
    }
};
