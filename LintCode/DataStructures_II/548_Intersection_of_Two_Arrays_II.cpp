class Solution {
public:
    /**
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        // write your code here

        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());

        std::vector<int> ans;
        int i = 0, j = 0;
        int size_1 = nums1.size(), size_2 = nums2.size();
        while (i < size_1 && j < size_2) {
            if (nums1[i] == nums2[j]) {
                ans.push_back(nums1[i]);
                ++i;
                ++j;
                continue;
            }

            if (nums1[i] < nums2[j]) {
                ++i;
            } else {
                ++j;
            }
        }

        return ans;
    }
};