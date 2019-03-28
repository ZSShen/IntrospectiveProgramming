class Solution {
public:
    /**
     * @param num: A list of integers
     * @return: An integer
     */
    int longestConsecutive(vector<int> &nums) {
        // write your code here
        /*
        std::sort(nums.begin(), nums.end());
        for (int num : nums) {
            cout << num << ' ';
        }
        */

        std::unordered_set<int> set;
        for (int num : nums) {
            set.insert(num);
        }

        int max = 0;
        while (!set.empty()) {

            int num = *set.begin();
            set.erase(num);
            int len = 1;

            int cand = num + 1;
            while (set.count(cand) == 1) {
                set.erase(cand);
                ++len;
                ++cand;
            }

            cand = num - 1;
            while (set.count(cand) == 1) {
                set.erase(cand);
                ++len;
                --cand;
            }

            if (len > max) {
                max = len;
            }
        }

        return max;
    }
};