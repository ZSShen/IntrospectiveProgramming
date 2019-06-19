class Solution {
public:
    /**
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    int woodCut(vector<int> &L, int k) {
        // write your code here

        /**
         *  n woods.
         *
         *  L1/S + L2/S + ... + Ln/S = k
         *
         *  S = 1,  L1 + L2 + ... + Ln
         *  S = 2,  L1/2 + L2/2 + ... + Ln/2
         *
         *  O(nL)
         *
         *  L = 1, R = Lmax
         *  S = M = (L + M) / 2
         *
         *  O(nlogL)
         */

        int l = 1, r = 0;
        for (int wood : L) {
            r = std::max(r, wood);
        }

        while (l + 1 < r) {
            int m = l + (r - l) / 2;

            if (countPieces(L, m) >= k) {
                l = m;
            } else {
                r = m;
            }
        }

        if (countPieces(L, l) < k) {
            return 0;
        }

        if (countPieces(L, r) == k) {
            return r;
        } else {
            return l;
        }
    }

private:
    int countPieces(const std::vector<int>& L, int s) {

        int sum = 0;
        for (int wood : L) {
            sum += wood / s;
        }
        return sum;
    }
};