class Solution {
public:
    /**
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        // write your code here

        std::unordered_set<int> set_1;
        for (int num : nums1) {
            set_1.insert(num);
        }

        std::unordered_set<int> inter;
        for (int num : nums2) {
            if (set_1.count(num) == 1) {
                inter.insert(num);
            }
        }

        std::vector<int> ans;
        for (auto num : inter) {
            ans.push_back(num);
        }

        return ans;
    }
};