class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here

        int ans = 0;
        int size = S.size();
        if (size < 3) {
            return ans;
        }

        std::sort(S.begin(), S.end());

        for (int i = 2 ; i < size ; ++i) {

            int l = 0, r = i - 1;
            while (l < r) {
                if (S[l] + S[r] > S[i]) {
                    ans += r - l;
                    --r;
                } else {
                    ++l;
                }
            }
        }

        return ans;
    }
};