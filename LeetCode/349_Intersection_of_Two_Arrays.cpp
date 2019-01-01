class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        std::unordered_map<int, bool> memo;
        for (int num : nums1) {
            memo[num] = true;
        }

        std::vector<int> intersect;
        for (int num : nums2) {
            if (memo.find(num) != memo.end() && memo[num]) {
                memo[num] = false;
                intersect.push_back(num);
            }
        }

        return intersect;
    }
};