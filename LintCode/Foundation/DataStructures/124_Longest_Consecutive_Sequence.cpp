class Solution {
public:
    /**
     * @param num: A list of integers
     * @return: An integer
     */
    int longestConsecutive(vector<int> &nums) {
        // write your code here

        std::unordered_set<int> set;
        for (int num : nums) {
            set.insert(num);
        }

        int max = 0;
        while (!set.empty()) {

            int len = 1;
            int seed = *set.begin();
            set.erase(seed);

            int forward = seed + 1;
            while (set.count(forward) == 1) {
                set.erase(forward);
                ++len;
                ++forward;
            }

            int backward = seed - 1;
            while (set.count(backward) == 1) {
                set.erase(backward);
                ++len;
                --backward;
            }

            max = std::max(max, len);
        }

        return max;
    }
};