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


class Solution {
public:
    /**
     * @param nums: A list of non negative integers
     * @return: A string
     */
    string largestNumber(vector<int> &nums) {
        // write your code here

        /**
         * A: 65, B: 6
         *
         * A + B = 656
         * B + A = 665
         *
         * B + A > A + B => B > A
         */

        std::unordered_map<int, int> radixes;
        for (int num : nums) {
            if (radixes.count(num) == 1) {
                continue;
            }
            int radix = (num > 0) ?
                static_cast<int>(std::floor(std::log10(num))) + 1 : 1;
            radixes[num] = radix;
        }

        std::sort(nums.begin(), nums.end(),
            [&] (const auto& a, const auto& b) {
                long ab = a * static_cast<long>(std::pow(10, radixes[b])) + b;
                long ba = b * static_cast<long>(std::pow(10, radixes[a])) + a;
                return ab > ba;
            }
        );

        std::string ans;
        for (int num : nums) {
            ans += std::to_string(num);
        }

        // For the case that the string content is 000...
        if (ans[0] == '0') {
            return "0";
        }

        return ans;
    }
};


class Solution {
public:
    /**
     * @param nums: A list of non negative integers
     * @return: A string
     */
    string largestNumber(vector<int> &nums) {
        // write your code here

        std::vector<std::string> strs;
        for (int num : nums) {
            strs.push_back(std::to_string(num));
        }

        std::sort(strs.begin(), strs.end(),
            [] (const auto& lhs, const auto& rhs) {

                /**
                 *  A: 65, B:6
                 *
                 *  A + B = 656
                 *  B + A = 665
                 *
                 *  B + A > A + B => B > A
                 *
                 */

                auto lpr = lhs + rhs;
                auto rpl = rhs + lhs;

                return lpr > rpl;
            }
        );

        std::string ans;
        for (const auto& str : strs) {
            ans += str;
        }

        // For the case that the string content is actually 000... .
        if (ans[0] == '0') {
            return "0";
        }

        return ans;
    }
};