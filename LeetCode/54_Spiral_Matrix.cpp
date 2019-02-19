class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        std::vector<int> ans;

        int m = matrix.size();
        if (m == 0) {
            return ans;
        }

        int n = matrix[0].size();
        if (n == 0) {
            return ans;
        }

        int bound_l = 0;
        int bound_r = n - 1;
        int bound_u = 0;
        int bound_d = m - 1;

        int r = 0, c = 0;
        Direct direct = Direct::R;
        for (int i = 0 ; i < m * n ; ++i) {
            ans.push_back(matrix[r][c]);

            switch (direct) {
                case Direct::R:
                    ++c;
                    if (c > bound_r) {
                        --c;
                        ++r;
                        direct = Direct::D;
                        ++bound_u;
                    }
                    break;
                case Direct::D:
                    ++r;
                    if (r > bound_d) {
                        --r;
                        --c;
                        direct = Direct::L;
                        --bound_r;
                    }
                    break;
                case Direct::L:
                    --c;
                    if (c < bound_l) {
                        ++c;
                        --r;
                        direct = Direct::U;
                        --bound_d;
                    }
                    break;
                case Direct::U:
                    --r;
                    if (r < bound_u) {
                        ++r;
                        ++c;
                        direct = Direct::R;
                        ++bound_l;
                    }
                    break;
            }
        }

        return ans;
    }

private:
    enum Direct {
        L,
        R,
        U,
        D
    };
};
