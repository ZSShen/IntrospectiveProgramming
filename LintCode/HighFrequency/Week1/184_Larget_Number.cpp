class Solution {
public:
    /**
     * @param nums: A list of non negative integers
     * @return: A string
     */
    string largestNumber(vector<int> &nums) {
        // write your code here

        /**
         *  1. same radix, larger number, higher order.
         *  2. different radixes, generate 2 synthetic numbers.
         *      lhs, rhs
         *      if lhs, rhs > rhs, lhs, lhs has the higher order.
         *      else,                 , rhs has the higher order.
         */

        if (nums.empty()) {
            return "";
        }

        std::sort(nums.begin(), nums.end(),
            [] (const auto& lhs, const auto& rhs) {

                // For radix comparsion, please take care of 0s.
                int r_lhs = (lhs > 0) ? std::log10(lhs) + 1 : 1;
                int r_rhs = (rhs > 0) ? std::log10(rhs) + 1 : 1;

                if (r_lhs == r_rhs) {
                    return lhs > rhs;
                }

                // The synthetic number may be greater than INT_MAX.
                unsigned long syn_lhs = lhs * std::pow(10, r_rhs) + rhs;
                unsigned long syn_rhs = rhs * std::pow(10, r_lhs) + lhs;

                return syn_lhs > syn_rhs;
            });

        // For 000000s...
        if (nums[0] == 0) {
            return "0";
        }

        std::string str;
        for (int num : nums) {
            str += std::to_string(num);
        }
        return str;
    }
};