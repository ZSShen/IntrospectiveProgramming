class Solution {
public:
    /**
     * @param arrs: the arrays
     * @return: the number of the intersection of the arrays
     */
    int intersectionOfArrays(vector<vector<int>> &arrs) {
        // write your code here

        int size = arrs.size();
        if (size == 0) {
            return 0;
        }

        for (auto& arr : arrs) {
            std::sort(arr.begin(), arr.end());
        }

        std::vector<int> inter(arrs[0]);
        for (int i = 1 ; i < size ; ++i) {
            std::vector<int> temp;

            int j = 0, k = 0;
            const auto& arr = arrs[i];
            int bnd_j = inter.size(), bnd_k = arr.size();

            while (j < bnd_j && k < bnd_k) {
                if (inter[j] == arr[k]) {
                    temp.push_back(inter[j]);
                    ++j;
                    ++k;
                    continue;
                }

                if (inter[j] > arr[k]) {
                    ++k;
                } else {
                    ++j;
                }
            }

            inter = std::move(temp);
        }

        return inter.size();
    }
};